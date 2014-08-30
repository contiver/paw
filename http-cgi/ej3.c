#include <stdio.h>
#include <stdlib.h>

int
main(void){
    char c;
    FILE *fp = fopen("products.txt", "r");

    printf("Server: Apache/2\n"
           "Content-type: text/html\n\n");
    if (fp == NULL){
        printf("<html><body><h1>No se encontro lista de productos</h1></body></html>");
	return 0;
    }
    printf("<html><body><h1>Lista de Productos</h1>\n");
    printf("<table><tr><td>Codigo");

    int code, price;
    size_t len = 0;
    char name[20];
    char *line = NULL;
    while ( getline(&line, &len, fp) != -1 ){
        sscanf(line, "%d,%[^,],%d", &code, name, &price);
        printf("<tr><td>%d</td><td>%s</td><td>%d</td></tr>", code, name, price);
    }

    printf("</table></body></html>");

    free(line);
    fclose(fp);
    return 0;
}
