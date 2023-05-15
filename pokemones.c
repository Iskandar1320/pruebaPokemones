#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>


char respuesta[40];
char dato1[40];
char dato2[40];
char dato3[40];
FILE *inFile;
FILE *fileNew;

typedef struct 
{
    int id;
    char name[64];
    char form[64];
    char type1[64];
    char type2[64];
    int total;
    int hp;
    int attack;
    int defense;
    int spAtk;
    int spDef;
    int speed;
    int generation;
} PokemonBase;

typedef struct Node {
    PokemonBase *pokemon;
    struct Node *next;
} Node;

Node *head = NULL; // cabeza de la lista dinámica

PokemonBase *pokemonSP;

int num_registro = 0;

void load()
{
    inFile = fopen(dato2, "r");
    
    char line[128];

    if (inFile == NULL)
    {
        printf("El archivo no fue encontrado\n");  
    } 
    else
    {

        pokemonSP = NULL;
        num_registro = 0;

        fgets(line,128,inFile);

        while (!feof(inFile))
        {
            PokemonBase pokemonS;

            int result = fscanf(inFile, "%d,\"%[^\"]\",\"%[^\"]\",\"%[^\"]\",\"%[^\"]\",%d,%d,%d,%d,%d,%d,%d,%d", 
            &pokemonS.id, pokemonS.name,pokemonS.form, pokemonS.type1, pokemonS.type2, &pokemonS.total, &pokemonS.hp,
             &pokemonS.attack, &pokemonS.defense,&pokemonS.spAtk, &pokemonS.spDef, &pokemonS.speed, &pokemonS.generation);  

            if( result == 13)
            {
                num_registro++;
                pokemonSP = realloc(pokemonSP, num_registro * sizeof(PokemonBase));
                pokemonSP[num_registro - 1] = pokemonS;
            }
        }
        printf("El archivo fue cargado \n");
    }

    fclose(inFile);
}

void size()
{
    printf("El numero de registro es igual a: %d \n", num_registro);
}

void range()
{
    int numero = atoi(dato2);

    for(int i = 0; i < numero; i++) 
    {
        printf("ID: %d, NAME: %s, FORM: %s, TYPE1: %s, TYPE2: %s, TOTAL: %d, HP: %d, ATTACK: %d, DEFENSE: %d, SP.ATK: %d, SP.DEF: %d, SPEED: %d, GENERATION: %d\n", 
        pokemonSP[i].id, pokemonSP[i].name, pokemonSP[i].form, pokemonSP[i].type1, pokemonSP[i].type2, pokemonSP[i].total, pokemonSP[i].hp,
        pokemonSP[i].attack, pokemonSP[i].defense, pokemonSP[i].spAtk, pokemonSP[i].spDef, pokemonSP[i].speed, pokemonSP[i].generation);
    }
}

void show()
{
    int numero = atoi(dato2);

    for (int i = 0; i < num_registro; i++)
    {
        if(pokemonSP[i].id == numero)
        {
            printf("ID: %d, NAME: %s, FORM: %s, TYPE1: %s, TYPE2: %s, TOTAL: %d, HP: %d, ATTACK: %d, DEFENSE: %d, SP.ATK: %d, SP.DEF: %d, SPEED: %d, GENERATION: %d\n", 
            pokemonSP[i].id, pokemonSP[i].name, pokemonSP[i].form, pokemonSP[i].type1, pokemonSP[i].type2, pokemonSP[i].total, pokemonSP[i].hp,
            pokemonSP[i].attack, pokemonSP[i].defense, pokemonSP[i].spAtk, pokemonSP[i].spDef, pokemonSP[i].speed, pokemonSP[i].generation);
        }
        else if (i == (num_registro))
        {
            printf("El id %d no fue encontrado.\n", numero);
        }
    }
}


void search()
{
    // inicializar la cabeza de la lista como nulo
    head = NULL;
    
    if(strcmp(dato2, "form") == 0)
    {
        for (int i = 0; i < num_registro; i++) 
        {
            if(strcmp(pokemonSP[i].form, dato3) == 0)
            {
                // crear un nuevo nodo de la lista dinámica
                Node *newNode = malloc(sizeof(Node));
                newNode->pokemon = &pokemonSP[i]; // asignar el puntero al Pokemon correspondiente
                newNode->next = NULL; // establecer el puntero al siguiente nodo como nulo
                
                // si la lista está vacía
                if (head == NULL) 
                { 
                    head = newNode; // el nuevo nodo es el primer nodo de la lista
                } 
                else 
                {
                    // recorrer la lista hasta el último nodo
                    Node *current = head;
                    while (current->next != NULL) 
                    {
                        current = current->next;
                    }
                    // establecer el puntero al siguiente nodo del último nodo como el nuevo nodo
                    current->next = newNode;
                }
            }
        }
        printf("Tu lista ha sido creada correctamente!.\n");
    }
    else if (strcmp(dato2, "type1") == 0)
    {
        for (int i = 0; i < num_registro; i++) 
        {
            if(strcmp(pokemonSP[i].type1, dato3) == 0)
            {
                // crear un nuevo nodo de la lista dinámica
                Node *newNode = malloc(sizeof(Node));
                newNode->pokemon = &pokemonSP[i]; // asignar el puntero al Pokemon correspondiente
                newNode->next = NULL; // establecer el puntero al siguiente nodo como nulo
                
                // si la lista está vacía
                if (head == NULL) 
                { 
                    head = newNode; // el nuevo nodo es el primer nodo de la lista
                } 
                else 
                {
                    // recorrer la lista hasta el último nodo
                    Node *current = head;
                    while (current->next != NULL) 
                    {
                        current = current->next;
                    }
                    // establecer el puntero al siguiente nodo del último nodo como el nuevo nodo
                    current->next = newNode;
                }
            }
        }
        printf("Tu lista ha sido creada correctamente!.\n");
    }
    else if (strcmp(dato2, "type2") == 0)
    {
        for (int i = 0; i < num_registro; i++) 
        {
            if(strcmp(pokemonSP[i].type2, dato3) == 0)
            {
                // crear un nuevo nodo de la lista dinámica
                Node *newNode = malloc(sizeof(Node));
                newNode->pokemon = &pokemonSP[i]; // asignar el puntero al Pokemon correspondiente
                newNode->next = NULL; // establecer el puntero al siguiente nodo como nulo
                
                // si la lista está vacía
                if (head == NULL) 
                { 
                    head = newNode; // el nuevo nodo es el primer nodo de la lista
                } 
                else 
                {
                    // recorrer la lista hasta el último nodo
                    Node *current = head;
                    while (current->next != NULL) 
                    {
                        current = current->next;
                    }
                    // establecer el puntero al siguiente nodo del último nodo como el nuevo nodo
                    current->next = newNode;
                }
            }
        }
        printf("Tu lista ha sido creada correctamente!.\n");
    }
    else if (strcmp(dato2, "total") == 0)
    {
        int valor = atoi(dato3);
        for (int i = 0; i < num_registro; i++) 
        {
            if(pokemonSP[i].total == valor)
            {
                // crear un nuevo nodo de la lista dinámica
                Node *newNode = malloc(sizeof(Node));
                newNode->pokemon = &pokemonSP[i]; // asignar el puntero al Pokemon correspondiente
                newNode->next = NULL; // establecer el puntero al siguiente nodo como nulo
                
                // si la lista está vacía
                if (head == NULL) 
                { 
                    head = newNode; // el nuevo nodo es el primer nodo de la lista
                } 
                else 
                {
                    // recorrer la lista hasta el último nodo
                    Node *current = head;
                    while (current->next != NULL) 
                    {
                        current = current->next;
                    }
                    // establecer el puntero al siguiente nodo del último nodo como el nuevo nodo
                    current->next = newNode;
                }
            }
        }
        printf("Tu lista ha sido creada correctamente!.\n");
    }
    else if (strcmp(dato2, "hp") == 0)
    {
        int valor = atoi(dato3);
        for (int i = 0; i < num_registro; i++) 
        {
            if(pokemonSP[i].hp == valor)
            {
                // crear un nuevo nodo de la lista dinámica
                Node *newNode = malloc(sizeof(Node));
                newNode->pokemon = &pokemonSP[i]; // asignar el puntero al Pokemon correspondiente
                newNode->next = NULL; // establecer el puntero al siguiente nodo como nulo
                
                // si la lista está vacía
                if (head == NULL) 
                { 
                    head = newNode; // el nuevo nodo es el primer nodo de la lista
                } 
                else 
                {
                    // recorrer la lista hasta el último nodo
                    Node *current = head;
                    while (current->next != NULL) 
                    {
                        current = current->next;
                    }
                    // establecer el puntero al siguiente nodo del último nodo como el nuevo nodo
                    current->next = newNode;
                }
            }
        }
        printf("Tu lista ha sido creada correctamente!.\n");
    }
    else if (strcmp(dato2, "attack") == 0)
    {
        int valor = atoi(dato3);
        for (int i = 0; i < num_registro; i++) 
        {
            if(pokemonSP[i].attack == valor)
            {
                // crear un nuevo nodo de la lista dinámica
                Node *newNode = malloc(sizeof(Node));
                newNode->pokemon = &pokemonSP[i]; // asignar el puntero al Pokemon correspondiente
                newNode->next = NULL; // establecer el puntero al siguiente nodo como nulo
                
                // si la lista está vacía
                if (head == NULL) 
                { 
                    head = newNode; // el nuevo nodo es el primer nodo de la lista
                } 
                else 
                {
                    // recorrer la lista hasta el último nodo
                    Node *current = head;
                    while (current->next != NULL) 
                    {
                        current = current->next;
                    }
                    // establecer el puntero al siguiente nodo del último nodo como el nuevo nodo
                    current->next = newNode;
                }
            }
        }
        printf("Tu lista ha sido creada correctamente!.\n");
    }
    else if (strcmp(dato2, "defense") == 0)
    {
        int valor = atoi(dato3);
        for (int i = 0; i < num_registro; i++) 
        {
            if(pokemonSP[i].defense == valor)
            {
                // crear un nuevo nodo de la lista dinámica
                Node *newNode = malloc(sizeof(Node));
                newNode->pokemon = &pokemonSP[i]; // asignar el puntero al Pokemon correspondiente
                newNode->next = NULL; // establecer el puntero al siguiente nodo como nulo
                
                // si la lista está vacía
                if (head == NULL) 
                { 
                    head = newNode; // el nuevo nodo es el primer nodo de la lista
                } 
                else 
                {
                    // recorrer la lista hasta el último nodo
                    Node *current = head;
                    while (current->next != NULL) 
                    {
                        current = current->next;
                    }
                    // establecer el puntero al siguiente nodo del último nodo como el nuevo nodo
                    current->next = newNode;
                }
            }
        }
        printf("Tu lista ha sido creada correctamente!.\n");
    }
    else if (strcmp(dato2, "sp.Atk") == 0)
    {
        int valor = atoi(dato3);
        for (int i = 0; i < num_registro; i++) 
        {
            if(pokemonSP[i].spAtk == valor)
            {
                // crear un nuevo nodo de la lista dinámica
                Node *newNode = malloc(sizeof(Node));
                newNode->pokemon = &pokemonSP[i]; // asignar el puntero al Pokemon correspondiente
                newNode->next = NULL; // establecer el puntero al siguiente nodo como nulo
                
                // si la lista está vacía
                if (head == NULL) 
                { 
                    head = newNode; // el nuevo nodo es el primer nodo de la lista
                } 
                else 
                {
                    // recorrer la lista hasta el último nodo
                    Node *current = head;
                    while (current->next != NULL) 
                    {
                        current = current->next;
                    }
                    // establecer el puntero al siguiente nodo del último nodo como el nuevo nodo
                    current->next = newNode;
                }
            }
        }
        printf("Tu lista ha sido creada correctamente!.\n");
    }
    else if (strcmp(dato2, "sp.Def") == 0)
    {
        int valor = atoi(dato3);
        for (int i = 0; i < num_registro; i++) 
        {
            if(pokemonSP[i].spDef == valor)
            {
                // crear un nuevo nodo de la lista dinámica
                Node *newNode = malloc(sizeof(Node));
                newNode->pokemon = &pokemonSP[i]; // asignar el puntero al Pokemon correspondiente
                newNode->next = NULL; // establecer el puntero al siguiente nodo como nulo
                
                // si la lista está vacía
                if (head == NULL) 
                { 
                    head = newNode; // el nuevo nodo es el primer nodo de la lista
                } 
                else 
                {
                    // recorrer la lista hasta el último nodo
                    Node *current = head;
                    while (current->next != NULL) 
                    {
                        current = current->next;
                    }
                    // establecer el puntero al siguiente nodo del último nodo como el nuevo nodo
                    current->next = newNode;
                }
            }
            printf("Tu lista ha sido creada correctamente!.\n");
        }
    }
    else if (strcmp(dato2, "speed") == 0)
    {
        int valor = atoi(dato3);
        for (int i = 0; i < num_registro; i++) 
        {
            if(pokemonSP[i].speed == valor)
            {
                // crear un nuevo nodo de la lista dinámica
                Node *newNode = malloc(sizeof(Node));
                newNode->pokemon = &pokemonSP[i]; // asignar el puntero al Pokemon correspondiente
                newNode->next = NULL; // establecer el puntero al siguiente nodo como nulo
                
                // si la lista está vacía
                if (head == NULL) 
                { 
                    head = newNode; // el nuevo nodo es el primer nodo de la lista
                } 
                else 
                {
                    // recorrer la lista hasta el último nodo
                    Node *current = head;
                    while (current->next != NULL) 
                    {
                        current = current->next;
                    }
                    // establecer el puntero al siguiente nodo del último nodo como el nuevo nodo
                    current->next = newNode;
                }
            }
        }
        printf("Tu lista ha sido creada correctamente!.\n");
    }
    else if (strcmp(dato2, "generation") == 0)
    {
        int valor = atoi(dato3);
        for (int i = 0; i < num_registro; i++) 
        {
            if(pokemonSP[i].generation == valor)
            {
                // crear un nuevo nodo de la lista dinámica
                Node *newNode = malloc(sizeof(Node));
                newNode->pokemon = &pokemonSP[i]; // asignar el puntero al Pokemon correspondiente
                newNode->next = NULL; // establecer el puntero al siguiente nodo como nulo
                
                // si la lista está vacía
                if (head == NULL) 
                { 
                    head = newNode; // el nuevo nodo es el primer nodo de la lista
                } 
                else 
                {
                    // recorrer la lista hasta el último nodo
                    Node *current = head;
                    while (current->next != NULL) 
                    {
                        current = current->next;
                    }
                    // establecer el puntero al siguiente nodo del último nodo como el nuevo nodo
                    current->next = newNode;
                }
            }
        }
        printf("Tu lista ha sido creada correctamente!.\n");
    }
    else
    {
        printf("los datos introducidos no son correctos");
    }
}

void showS()
{
    Node *current = head;
    while (current != NULL) {
        printf("ID: %d, Nombre: %s, Forma: %s, Tipo 1: %s, Tipo 2: %s, Total: %d, HP: %d, Ataque: %d, Defensa: %d, Sp. Atk: %d, Sp. Def: %d, Velocidad: %d, Generación: %d\n", 
               current->pokemon->id, current->pokemon->name, current->pokemon->form, current->pokemon->type1, current->pokemon->type2, current->pokemon->total,
               current->pokemon->hp, current->pokemon->attack, current->pokemon->defense, current->pokemon->spAtk, current->pokemon->spDef, current->pokemon->speed, current->pokemon->generation);
        current = current->next;
    }
}

void save()
{
    fileNew = fopen(dato2, "w");
    if (fileNew == NULL) 
    {
        printf("No se pudo crear el archivo.\n");
    }

    Node *current = head;
    while (current != NULL) {
        fprintf(fileNew, "%d,\"%s\",\"%s\",\"%s\",\"%s\",%d,%d,%d,%d,%d,%d,%d,%d\n", 
            current->pokemon->id, current->pokemon->name, current->pokemon->form, 
            current->pokemon->type1, current->pokemon->type2, current->pokemon->total, 
            current->pokemon->hp, current->pokemon->attack, current->pokemon->defense, 
            current->pokemon->spAtk, current->pokemon->spDef, current->pokemon->speed, 
            current->pokemon->generation);
        current = current->next;
    }

    fclose(fileNew);
}

int main(void)
{
    while(1)
    {
        printf("Escribe la opcion: ");

        if(fgets(respuesta, 40, stdin) != NULL)
        {
            respuesta[strlen(respuesta) - 1] = 0;
        }

        sscanf(respuesta, "%s %s %s", dato1, dato2, dato3);

        if(strcmp(dato1, "exit") == 0)
        {
            printf("Saliste de la aplicacion. \n");
            break;
        }

        else if(strcmp(dato1, "load") == 0)
        {
            load();
        }

        else if(strcmp(dato1, "size") == 0)
        {
            size();
        }

        else if(strcmp(dato1, "range") == 0)
        {
            range();
        }

        else if(strcmp(dato1, "show") == 0 && strcmp(dato2, "search") != 0)
        {
            show();
        }

        else if(strcmp(dato1, "search") == 0)
        {
            search();
        }

        else if(strcmp(dato1, "show") == 0 && strcmp(dato2, "search") == 0)
        {
            printf("si entre");
            showS();
        }

        else if(strcmp(dato1, "save") == 0)
        {
            save();
        }
        
        else
        {
            printf("El dato escrito no es valido. \n");
        }
    }
}