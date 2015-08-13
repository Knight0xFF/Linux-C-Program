#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main()
{
    uid_t uid;
    gid_t gid;
    uid = getuid();
    gid = getgid();

    printf("user name: %s \n", getlogin());
    printf("uid = %d\n", uid);
    printf("gid = %d\n", gid);

    struct passwd *user;
    user = getpwent();
    while (user != NULL)
    {
        printf("%s:%d:%d:%s:%s:%s\n", user->pw_name, user->pw_uid, user->pw_gid,
                user->pw_gecos, user->pw_dir, user->pw_shell);
        user = getpwent();
    }
    endpwent();


    user = getpwnam("root");
    printf("%s:%d:%d:%s:%s:%s\n", user->pw_name, user->pw_uid, user->pw_gid,
            user->pw_gecos, user->pw_dir, user->pw_shell);


    return 0;
}
