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
    printf("<table><tr><td>Codigo</td><td>Nombre</td><td>Precio</td></tr>");

    int code, price, from, to;
    char name[20];
    char *line = NULL;
    size_t len = 0;

    if(qs != NULL){
        sscanf(qs, "%[^f]from=%d", &from);
        sscanf(qs, "%[^t]to=%d", &to);
        while ( getline(&line, &len, fp) != -1 ){
            sscanf(line, "%d,%[^,],%d", &code, name, &price);
            if(from <= price && price <= to){
                printf("<tr><td>%d</td><td>%s</td><td>%d</td></tr>", code, name, price);
            }
        }
    }else{
        while ( getline(&line, &len, fp) != -1 ){
            sscanf(line, "%d,%[^,],%d", &code, name, &price);
            printf("<tr><td>%d</td><td>%s</td><td>%d</td></tr>", code, name, price);
        }
    }

    printf("</table></body></html>");

    free(line);
    fclose(fp);
    exit(EXIT_SUCCESS);
}
