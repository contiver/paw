#include <stdio.h>
#include <stdlib.h>

int
main(void){
    char c;
    char *qs = getenv("QUERY_STRING");
    FILE *fp = fopen("products.txt", "r");

    printf("Server: Apache/2\n"
           "Content-type: text/html\n\n");
    if (fp == NULL){
        printf("<html><body><h1>No se encontro lista de productos</h1></body></html>");
	return 0;
    }
    printf("<html><body><h1>Lista de Productos</h1>\n");
    printf("<table><tr><td>Codigo");

    while( (c = fgetc(fp)) != EOF){
        printf("<tr><td>%c",c);
        while( (c = fgetc(fp)) != '\n'){
            if (c == ',') printf("</td><td>");
            else printf("%c",c);
        }
        printf("</td></tr>");
    }

    printf("</table></body></html>");

    fclose(fp);
    return 0;
}
