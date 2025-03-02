#include <stdlib.h>

#include <switch.h>

#ifndef NXSH_H
#define NXSH_H

/* Useful constants */
#define NXSH_WELCOME "Welcome to nxsh! Type 'help' for a list of available commands.\r\n"
#define NXSH_SEPARATOR "-------------------------------------------------------------\r\n"
#define NXSH_HELP "List of available commands:\r\n" \
                    "\tls - get a directory listing\r\n" \
                    "\tcd - change directory\r\n" \
                    "\tmkdir - make directory\r\n" \
                    "\trm - remove file or directory\r\n" \
                    "\tcp - copy file or directory\r\n" \
                    "\tcat - print file on standard output\r\n" \
                    "\tpasswd - set/update/clear password\r\n" \
                    "\tlog - enable/disable logging\r\n" \
                    "\tfetch - download file from remote server\r\n" \
                    "\tmount - mount a filesystem to a device\r\n" \
                    "\tumount - unmount device\r\n" \
                    "\tcommit-dev - commit changes to a device\r\n" \
                    "\treboot - reboots the console\r\n" \
                    "\tshutdown - turns off the console\r\n" \
                    "\techo - echo the arguments\r\n" \
                    "\ttouch - create file or update modification date of a file\r\n" \
                    "\tmd5sum - get the md5 hash of a file\r\n" \
                    "\tsha1sum - get the sha1 hash of a file\r\n" \
                    "\tsha256sum - get the sha256 hash of a file\r\n" \
                    "\tpm - interact with the PM sysmodule\r\n" \
                    "\tacc - interact with accounts\r\n" \
                    "\trealpath - resolve the absolute path\r\n" \
                    "\tversion - display NXSH version\r\n" \
                    "\thelp - print this message\r\n\r\n" \
                    "\tInvoke script files by their path (./script.js)\r\n"

#define NXSH_DIR "/nxsh"

#define NXSH_VERSION "0.1.8 beta"

#define NXSH_PORT 3005

extern int NXSH_LOGGING_ENABLED;
extern int NXSH_FD_LOCK;

/* Functions in main.c */
void nxsh_session(int connfd);
char *nxsh_command(int connfd, char *command, int argc, char **argv);

/* Basic shell commands */
char *nxsh_ls(int argc, char **argv);
char *nxsh_cd(int argc, char **argv);
char *nxsh_mkdir(int argc, char **argv);
char *nxsh_rm(int argc, char **argv);
char *nxsh_cp(int argc, char **argv);
char *nxsh_mv(int argc, char **argv);
char *nxsh_chmod(int argc, char **argv);
char *nxsh_cat(int argc, char **argv);
char *nxsh_log(int argc, char **argv);
char *nxsh_passwd(int argc, char **argv);
char *nxsh_fetch(int argc, char **argv, int connfd);
char *nxsh_script(char *path, int argc, char **argv, int connfd);
char *nxsh_mount(int argc, char **argv);
char *nxsh_umount(int argc, char **argv);
char *nxsh_reboot(int argc, char **argv, int connfd);
char *nxsh_shutdown(int connfd);
char *nxsh_echo(int argc, char **argv);
char *nxsh_touch(int argc, char **argv);
char *nxsh_hash(int argc, char **argv, const char *type);
char *nxsh_pm(int argc, char **argv);
char *nxsh_acc(int argc, char **argv);
char *nxsh_commit_dev(int argc, char **argv);
char *nxsh_realpath(int argc, char **argv);

/* Behind the scenes */
char *nxsh_cwd();
char *nxsh_prompt();
int nxsh_authenticate(char *password);

/* Logging functions */
int logging_enabled();
void write_log(char *input);
void write_log_raw(char *input);

/* Utility functions */
void trim(char *input);
void delete_end(char *input);
char *error(char *msg);
int is_file(char *name);
int is_dir_empty(char *dir);
int exists(char *name);
char *filename(char *fullpath);
char *strip_prefix(char *inpath);
char *hash(void *input, size_t size, const char *type);
char *format_acc_uid_hex(AccountUid uid);

#endif
