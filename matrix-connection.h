/**
 * matrix-connection.h: handle the connection to a matrix homeserver
 *
 * When matrix_connection_start_login is called, we first get an access
 * token by calling /login. We then repeatedly poll the /sync API endpoint.
 * Each time /sync returns, the returned events are dispatched to the
 * relevant rooms, and another /sync request is started.
 *
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02111-1301 USA
 */

#ifndef MATRIX_CONNECTION_H
#define MATRIX_CONNECTION_H

#include <glib.h>

struct _PurpleConnection;

typedef struct _MatrixConnectionData {
    struct _PurpleConnection *pc;
    gchar *homeserver;      /* hostname (:port) of the homeserver */
    gchar *access_token;    /* access token corresponding to our user */
} MatrixConnectionData;


/**
 * Allocate a new MatrixConnectionData for the given PurpleConnection
 */
void matrix_connection_new(struct _PurpleConnection *pc);

/**
 * Start the login process on a matrix connection. When this completes, it
 * will start the /sync loop
 */
void matrix_connection_start_login(struct _PurpleConnection *pc);

/**
 * free the resources associated with a PurpleConnection
 */
void matrix_connection_free(struct _PurpleConnection *pc);


#endif
