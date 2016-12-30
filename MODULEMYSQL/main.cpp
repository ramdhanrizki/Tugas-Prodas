#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <mysql/mysql.h>
#include <stdlib.h>
#include <conio.h>

static char *opt_host_name = "localhost"; /* server host (default=localhost) */
static char *opt_user_name = "root"; /* username (default=login name) */
static char *opt_password = ""; /* password (default=none) */
static unsigned int opt_port_num = 3306; /* port number (use built-in value) */
static char *opt_socket_name = NULL; /* socket name (use built-in value) */
static char *opt_db_name = "mysql"; /* database name (default=none) */
static unsigned int opt_flags = 0; /* connection flags (none) */

using namespace std;

int main(int argc, char *argv[])
{
    MYSQL *conn; 
    MYSQL_RES *res; // Result Set 
    MYSQL_ROW row; 
    
    conn = mysql_init(NULL); 
    
    //koneksi ke server 
    mysql_real_connect (conn, opt_host_name, opt_user_name, opt_password,
    opt_db_name, opt_port_num, opt_socket_name, opt_flags);
    
    //Show tables
    mysql_query(conn,"use comrades");
     
    //select comrades 
    mysql_query(conn,"select * from kategori"); 
    res = mysql_use_result(conn); 
    
    printf("Kategori\n"); 
    while((row=mysql_fetch_row(res)) != NULL)
       printf("%s \n", row[1]);
    
    //diskonek ke server 
    mysql_close(conn); 
    
    printf("Press any key to continue...");
    getch(); 
    return 0;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
