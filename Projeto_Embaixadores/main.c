#include <stdio.h>
#include <string.h> 
#include <ctype.h>
#include <time.h>

void alterar_info_visita(void) { printf("Funcionalidade não implementada.\n"); }
void alterar_info_embaixador(void) { printf("Funcionalidade não implementada.\n"); }
void eliminar_visita(void) { printf("Funcionalidade não implementada.\n"); }
void eliminar_embaixador(void) { printf("Funcionalidade não implementada.\n"); }
void gravar_dados(void) { printf("Funcionalidade não implementada.\n"); }
void relatorio_desempenho(void) { printf("Funcionalidade não implementada.\n"); }
void taxa_sucesso(void) { printf("Funcionalidade não implementada.\n"); }
void media_emb_por_visita(void) { printf("Funcionalidade não implementada.\n"); }



typedef struct embaixador{
    int numero;
    char escola[5];    
    char nome[50];     
    char nif[10];
}Embaixador;

typedef struct visita {
    int id;
    char estado[11]; // em planeamento, autorizada, cancelada ou realizada
    char local[100];
    int dia;
    int mes;
    int ano;
}Visita;

#define MAX_EMBAIXADORES 100
#define MAX_VISITAS 1000

void ciclo_menu(void);
void listar_visitas(Visita lista_visita[], int nVisitas);
void listar_embaixadores(Embaixador lista[], int nEmbaixadores);
void consultar_visita(Visita lista_visita[], int nVisitas);
void consultar_embaixador(Embaixador lista[], int nEmbaixadores);
void adicionar_visita(Visita visita[], int *nVisita);
void adicionar_embaixador(Embaixador lista[], int *nEmbaixadores);
void autorizar_visita(Visita lista_visita[], int nVisitas);
void cancelar_visita(Visita lista_visita[], int nVisitas);
void confirmar_realizacao(Visita lista_visita[], int nVisitas);
void alterar_info_visita(void);
void alterar_info_embaixador(void);
void eliminar_visita(void);
void eliminar_embaixador(void);
void gravar_dados(void);
void relatorio_desempenho(void);
void taxa_sucesso(void);
void media_emb_por_visita(void);

int main()
{
    ciclo_menu();
    return 0;
}

void ciclo_menu(void) {
    int opt = 0;
    int nEmbaixadores = 0;
    int TST=0;
    int nVisita = 0;
    Embaixador embaixador[MAX_EMBAIXADORES];
    Visita visita[MAX_VISITAS]; 

    do {
        printf("\n=== Menu E-IPS ===\n");
        printf("1. Listar visitas (total)\n");
        printf("2. Listar embaixadores\n");
        printf("3. Consultar visita por ID\n");
        printf("4. Consultar embaixador\n");
        printf("5. Adicionar visita\n");
        printf("6. Adicionar embaixador\n");
        printf("7. Autorizar visita\n");
        printf("8. Cancelar visita\n");
        printf("9. Confirmar realização\n");
        printf("10. Alterar visita\n");
        printf("11. Alterar embaixador\n");
        printf("12. Eliminar visita\n");
        printf("13. Eliminar embaixador\n");
        printf("14. Gravar ficheiros\n");
        printf("15. Sair\n");
        printf("16. Relatório de desempenho\n");
        printf("17. Taxa de sucesso\n");
        printf("18. Média de embaixadores por visita\n");
        printf("Escolha: ");
        scanf("%d",&opt);

        switch (opt) {
            case 1: listar_visitas(visita , nVisita); break;
            case 2: listar_embaixadores(embaixador, nEmbaixadores); break;
            case 3: consultar_visita(visita , nVisita); break;
            case 4: consultar_embaixador(embaixador, nEmbaixadores); break;
            case 5: adicionar_visita(visita, &nVisita); break;
            case 6: adicionar_embaixador(embaixador, &nEmbaixadores); break;
            case 7: autorizar_visita(visita , nVisita); break;
            case 8: cancelar_visita(visita , nVisita); break;
            case 9: confirmar_realizacao(visita , nVisita); break;
            case 10: alterar_info_visita(); break;
            case 11: alterar_info_embaixador(); break;
            case 12: eliminar_visita(); break;
            case 13: eliminar_embaixador(); break;
            case 14: gravar_dados(); break;
            case 15: printf("A sair...\n"); break;
            case 16: relatorio_desempenho(); break;
            case 17: taxa_sucesso(); break;
            case 18: media_emb_por_visita(); break;
            default: printf("Opção inválida.\n");
        }

    } while (opt != 15);
}

void listar_embaixadores(Embaixador lista[], int nEmbaixadores) {
    if (nEmbaixadores == 0) {
        printf("Nenhum embaixador registado.\n");
        return;
    }
    for (int i = 0; i < nEmbaixadores; i++) {
        printf("%d: %s, Escola: %s, NIF: %s\n",
            lista[i].numero,
            lista[i].nome,
            lista[i].escola,
            lista[i].nif);
    }
}

// ---------------- ADICIONAR EMBAIXADOR ----------------

void adicionar_embaixador(Embaixador lista[], int *nEmbaixadores) {
    if (*nEmbaixadores >= MAX_EMBAIXADORES) {
        printf("Limite de embaixadores atingido!\n");
        return;
    }

    Embaixador e;

    printf("Número do estudante: ");
    scanf("%d", &e.numero);

    for (int i = 0; i < *nEmbaixadores; i++) {
        if (lista[i].numero == e.numero) {
            printf("Número já existe! Tente outro.\n");
            return;
        }
    }

    printf("Nome completo: ");
    scanf(" %49[^\n]", e.nome);

    printf("Escola (ESTS/ESTB/ESE/ESCE/ESS): ");
    scanf(" %4s", e.escola);

    int valido = 0;
    while (!valido) {
        printf("NIF (9 dígitos): ");
        scanf(" %9s", e.nif);

        if (strlen(e.nif) != 9) {
            printf("NIF inválido! Deve ter 9 dígitos.\n");
            continue;
        }

        valido = 1;
        for (int i = 0; i < 9; i++) {
            if (!isdigit(e.nif[i])) {
                printf("NIF inválido! Apenas números.\n");
                valido = 0;
                break;
            }
        }

        if (valido) {
            for (int i = 0; i < *nEmbaixadores; i++) {
                if (strcmp(lista[i].nif, e.nif) == 0) {
                    printf("NIF já existe!\n");
                    valido = 0;
                    break;
                }
            }
        }
    }

    lista[*nEmbaixadores] = e;
    (*nEmbaixadores)++;
    printf("Embaixador adicionado com sucesso!\n");
}

// ---------------- ADICIONAR VISITA ----------------

void adicionar_visita(Visita lista_visita[], int *nVisita) {
    static int proxID = 1;

    if (*nVisita >= MAX_VISITAS) {
        printf("Limite de visitas atingido!\n");
        return;
    }

    Visita v;
    v.id = proxID++;
    printf("Insira o local da visita: ");
    scanf(" %99[^\n]", v.local);
    printf("Insira a data da visita (dd mm aaaa): ");
    scanf("%d %d %d", &v.dia, &v.mes, &v.ano);

    v.estado[0] = 'e';
    v.estado[1] = '\0';

    lista_visita[*nVisita] = v;
    (*nVisita)++;
    printf("Visita adicionada com sucesso!\n");
}




// -------------------- LISTAR VISITAS ----------------
void listar_visitas(Visita lista_visitas[], int nVisitas) {
    if (nVisitas == 0) {
        printf("Nenhuma visita registada.\n");
        return;
    }
    for (int i = 0; i < nVisitas ; i++) {
        const char *estado_txt = "desconhecido";
        if (lista_visitas[i].estado[0] == 'e') estado_txt = "em planeamento";
        else if (lista_visitas[i].estado[0] == 'a') estado_txt = "autorizada";
        else if (lista_visitas[i].estado[0] == 'c') estado_txt = "cancelada";
        else if (lista_visitas[i].estado[0] == 'r') estado_txt = "realizada";

        printf("ID - %d, Estado: %s, Local: %s, Data: %02d-%02d-%04d\n",
            lista_visitas[i].id,
            estado_txt,
            lista_visitas[i].local,
            lista_visitas[i].dia,
            lista_visitas[i].mes,
            lista_visitas[i].ano);
    }
}

// ---------------- AUTORIZAR VISITA ----------------

void autorizar_visita(Visita lista_visita[], int nVisitas) {
    int id, i;
    char c;

    printf("Indique o ID da visita a autorizar: ");
    scanf("%d", &id);

    for (i = 0; i < nVisitas; i++) {
        if (lista_visita[i].id == id) {

            if (lista_visita[i].estado[0] != 'e') {
                printf("Visita não está em planeamento.\n");
                return;
            }

            printf("Autorizar visita? (s/n): ");
            scanf(" %c", &c);

            if (c == 's' || c == 'S') {
                lista_visita[i].estado[0] = 'a';
                printf("Visita autorizada.\n");
            } else {
                printf("Operação cancelada.\n");
            }
            return;
        }
    }

    printf("Visita não encontrada.\n");
}

// ---------------- CANCELAR VISITA ----------------

void cancelar_visita(Visita lista_visita[], int nVisitas) {
    int id, i;
    char c;

    printf("Indique o ID da visita a cancelar: ");
    scanf("%d", &id);

    for (i = 0; i < nVisitas; i++) {
        if (lista_visita[i].id == id) {

            if (lista_visita[i].estado[0] != 'e') {
                printf("Visita não está em planeamento.\n");
                return;
            }

            printf("Cancelar visita? (s/n): ");
            scanf(" %c", &c);

            if (c == 's' || c == 'S') {
                lista_visita[i].estado[0] = 'c';
                printf("Visita cancelada.\n");
            } else {
                printf("Operação cancelada.\n");
            }
            return;
        }
    }

    printf("Visita não encontrada.\n");
}

// ---------------- CONFIRMAR REALIZAÇÃO ----------------

void confirmar_realizacao(Visita lista_visita[], int nVisitas) {
    int id, i;

    printf("Insira o ID da visita: ");
    if (scanf("%d", &id) != 1) {
        printf("Entrada inválida.\n");
        return;
    }

    time_t t = time(NULL);
    struct tm *tm_now = localtime(&t);
    int ano_atual = tm_now->tm_year + 1900;
    int mes_atual = tm_now->tm_mon + 1;
    int dia_atual = tm_now->tm_mday;

    for (i = 0; i < nVisitas; i++) {
        if (lista_visita[i].id == id) {

            if (lista_visita[i].estado[0] != 'a') {
                printf("Visita não está autorizada.\n");
                return;
            }

            int data_passada =
                (lista_visita[i].ano < ano_atual) ||
                (lista_visita[i].ano == ano_atual && lista_visita[i].mes < mes_atual) ||
                (lista_visita[i].ano == ano_atual && lista_visita[i].mes == mes_atual && lista_visita[i].dia < dia_atual);

            if (!data_passada) {
                printf("Data ainda não passou.\n");
                return;
            }

            lista_visita[i].estado[0] = 'r';
            printf("Visita realizada.\n");
            return;
        }
    }

    printf("Visita não encontrada.\n");
}



void consultar_visita(Visita lista_visita[], int nVisitas) {
    int id = 0;
    printf("Insira o ID da visita: ");
    scanf("%d", &id);

    for (int i = 0; i < nVisitas; i++) {
        if (lista_visita[i].id == id) {
            const char *estado_txt = "desconhecido";
            if (lista_visita[i].estado[0] == 'e') estado_txt = "em planeamento";
            else if (lista_visita[i].estado[0] == 'a') estado_txt = "autorizada";
            else if (lista_visita[i].estado[0] == 'c') estado_txt = "cancelada";
            else if (lista_visita[i].estado[0] == 'r') estado_txt = "realizada";

            printf("ID - %d, Estado: %s, Local: %s, Data: %02d-%02d-%04d\n",
                lista_visita[i].id,
                estado_txt,
                lista_visita[i].local,
                lista_visita[i].dia,
                lista_visita[i].mes,
                lista_visita[i].ano);
            return;
        }
    }

    printf("Visita não encontrada.\n");
}

void consultar_embaixador(Embaixador lista[], int nEmbaixadores) {
    int numero = 0;
    printf("Insira o número do embaixador: ");
    scanf("%d", &numero);

    for (int i = 0; i < nEmbaixadores; i++) {
        if (lista[i].numero == numero) {
            printf("%d: %s, Escola: %s, NIF: %s\n",
                lista[i].numero,
                lista[i].nome,
                lista[i].escola,
                lista[i].nif);
            return;
        }
    }

    printf("Embaixador não encontrado.\n");
}
