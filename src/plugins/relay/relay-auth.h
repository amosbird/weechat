/*
 * Copyright (C) 2003-2020 Sébastien Helleu <flashcode@flashtux.org>
 *
 * This file is part of WeeChat, the extensible chat client.
 *
 * WeeChat is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * WeeChat is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with WeeChat.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef WEECHAT_PLUGIN_RELAY_AUTH_H
#define WEECHAT_PLUGIN_RELAY_AUTH_H

struct t_relay_client;

enum t_relay_auth_password
{
    RELAY_AUTH_PASSWORD_PLAIN = 0,
    RELAY_AUTH_PASSWORD_SHA256,
    RELAY_AUTH_PASSWORD_SHA512,
    RELAY_AUTH_PASSWORD_PBKDF2_SHA256,
    RELAY_AUTH_PASSWORD_PBKDF2_SHA512,
    /* number of password auths */
    RELAY_NUM_PASSWORD_AUTHS,
};

extern char *relay_auth_password_name[];

extern int relay_auth_password_search (const char *name);
extern char *relay_auth_generate_nonce ();
extern int relay_auth_check_password_plain (const char *password,
                                            const char *relay_password);
extern int relay_auth_password (struct t_relay_client *client,
                                const char *password,
                                const char *relay_password);
extern void relay_auth_parse_sha (const char *parameters,
                                  char **salt_hexa,
                                  char **salt,
                                  int *salt_size,
                                  char **hash);
extern void relay_auth_parse_pbkdf2 (const char *parameters,
                                     char **salt_hexa,
                                     char **salt,
                                     int *salt_size,
                                     int *iterations,
                                     char **hash);
extern int relay_auth_check_salt (struct t_relay_client *client,
                                  const char *salt_hexa);
extern int relay_auth_check_hash_sha (const char *hash_algo,
                                      const char *salt,
                                      int salt_size,
                                      const char *hash_sha,
                                      const char *relay_password);
extern int relay_auth_check_hash_pbkdf2 (const char *hash_pbkdf2_algo,
                                         const char *salt,
                                         int salt_size,
                                         int iterations,
                                         const char *hash_pbkdf2,
                                         const char *relay_password);
extern int relay_auth_password_hash (struct t_relay_client *client,
                                     const char *hashed_password,
                                     const char *relay_password);

#endif /* WEECHAT_PLUGIN_RELAY_AUTH_H */
