#include <stdio.h>

int
main(void){
    printf("<html><body>Hello world!</body></html>");
    return 0;
}
/* En error.log dice:
 * [Tue Aug 26 20:29:58.330244 2014] [cgi:error] [pid 5490:tid 140281771370240]
 * [client 127.0.0.1:35547] End of script output before headers: hello1.cgi
 */
