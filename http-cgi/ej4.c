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
    char attr[2][20];
    int i;

    if( qs != "" ){ // FIXME buscar la condición correcta para un query string vacio!
        sscanf(qs,"%[^&]&%s", attr[0], attr[1]);
	for(i = 0; i < 2; i++){
            sscanf(attr[i], "from=%d", &from);
            sscanf(attr[i], "to=%d", &to);
        }
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
