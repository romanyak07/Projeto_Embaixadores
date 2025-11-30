#include <stdio.h>
#include <string.h> 
#include <ctype.h>

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

void ciclo_menu(void);
void listar_visitas(int filtro);
void listar_embaixadores(Embaixador lista[], int nEmbaixadores);
void consultar_visita(void);
void consultar_embaixador(void);
void adicionar_visita(void);
void adicionar_embaixador(Embaixador lista[], int *nEmbaixadores);
void autorizar_visita(void);
void cancelar_visita(void);
void confirmar_realizacao(void);
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
    void ciclo_menu(void);
    ciclo_menu();

    
    return 0;
}










void ciclo_menu(void) {
    int opt = 0;
    int nEmbaixadores = 0;
    Embaixador embaixador[MAX_EMBAIXADORES];

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
            case 1: listar_visitas(0); break;
            case 2: listar_embaixadores(embaixador, nEmbaixadores); break;
            case 3: consultar_visita(); break;
            case 4: consultar_embaixador(); break;
            case 5: adicionar_visita(); break;
            case 6: adicionar_embaixador(embaixador, &nEmbaixadores); break;
            case 7: autorizar_visita(); break;
            case 8: cancelar_visita(); break;
            case 9: confirmar_realizacao(); break;
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


// Função para adicionar embaixador
void adicionar_embaixador(Embaixador lista[], int *nEmbaixadores) {
    if (*nEmbaixadores >= MAX_EMBAIXADORES) {
        printf("Limite de embaixadores atingido!\n");
        return;
    }

    Embaixador e;

    // Número do estudante
    printf("Número do estudante: ");
    scanf("%d", &e.numero);

    for (int i = 0; i < *nEmbaixadores; i++) {
        if (lista[i].numero == e.numero) {
            printf("Número já existe! Tente outro.\n");
            return;
        }
    }

    // Nome completo
    printf("Nome completo: ");
    scanf(" %49[^\n]", e.nome);

    // Escola
    printf("Escola (ESTS/ESTB/ESE/ESCE/ESS): ");
    scanf(" %4s", e.escola);

    // NIF
    int valido = 0;
    while (!valido) {
        printf("NIF (9 dígitos): ");
        scanf(" %9s", e.nif);  // lê como string

        // verifica comprimento
        if (strlen(e.nif) != 9) {
            printf("NIF inválido! Deve ter 9 dígitos.\n");
            continue;
        }

        // verifica se todos são dígitos
        valido = 1;
        for (int i = 0; i < 9; i++) {
            if (!isdigit(e.nif[i])) {
                printf("NIF inválido! Apenas números são permitidos.\n");
                valido = 0;
                break;
            }
        }

        // verifica duplicado
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

    // Adiciona à lista
    lista[*nEmbaixadores] = e;
    (*nEmbaixadores)++;
    printf("Embaixador adicionado com sucesso!\n");
}


// Função para listar embaixadores
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

// Funções stub para evitar erros de ligação
void listar_visitas(int filtro) {
    printf("Funcionalidade não implementada.\n");
}

void consultar_visita(void) {
    printf("Funcionalidade não implementada.\n");
}

void consultar_embaixador(void) {
    printf("Funcionalidade não implementada.\n");
}

void adicionar_visita(void) {
    printf("Funcionalidade não implementada.\n");
}

void autorizar_visita(void) {
    printf("Funcionalidade não implementada.\n");
}

void cancelar_visita(void) {
    printf("Funcionalidade não implementada.\n");
}

void confirmar_realizacao(void) {
    printf("Funcionalidade não implementada.\n");
}

void alterar_info_visita(void) {
    printf("Funcionalidade não implementada.\n");
}

void alterar_info_embaixador(void) {
    printf("Funcionalidade não implementada.\n");
}

void eliminar_visita(void) {
    printf("Funcionalidade não implementada.\n");
}

void eliminar_embaixador(void) {
    printf("Funcionalidade não implementada.\n");
}

void gravar_dados(void) {
    printf("Funcionalidade não implementada.\n");
}

void relatorio_desempenho(void) {
    printf("Funcionalidade não implementada.\n");
}

void taxa_sucesso(void) {
    printf("Funcionalidade não implementada.\n");
}

void media_emb_por_visita(void) {
    printf("Funcionalidade não implementada.\n");
}


