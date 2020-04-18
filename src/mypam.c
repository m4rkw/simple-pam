#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>

/* expected hook */
PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) {
  return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv) {
  printf("Acct mgmt\n");
  return PAM_SUCCESS;
}

/* expected hook, this is where custom stuff happens */
PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) {
  int retval;

  const char* pUsername;
  retval = pam_get_user(pamh, &pUsername, "Username: ");

  if (retval != PAM_SUCCESS) {
    return retval;
  }

  retval = system("/usr/local/bin/touchid");

  if (retval != 0) {
    return PAM_AUTH_ERR;
  }

  return PAM_SUCCESS;
}
