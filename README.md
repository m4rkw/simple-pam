# simple-pam fork showing how to use touchID authentication remotely

See: https://m4.rkw.io/blog/how-to-use-touchid-for-sudo-remotely-over-ssh.html

**Build the PAM module**

`sudo apt install libpam-dev`

`gcc -fPIC -fno-stack-protector -c src/mypam.c`

`sudo ld -x --shared -o /lib/security/mypam.so mypam.o`

**Enable the pam module**

Add to /etc/pam.d/sudo:

````
auth sufficient mypam.so
````
