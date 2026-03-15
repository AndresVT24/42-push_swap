#include "push_swap.h"

// --- FUNCIONES AUXILIARES SOLO PARA TESTEAR ---

// Crea un nuevo nodo
t_stack *nuevo_nodo(int num)
{
    t_stack *nodo = malloc(sizeof(t_stack));
    if (!nodo)
        return (NULL);
    nodo->num = num;
    nodo->next = NULL;
    return (nodo);
}

// Añade un nodo al final de la lista
void agregar_nodo_atras(t_stack **lst, int num)
{
    t_stack *nuevo;
    t_stack *temp;

    nuevo = nuevo_nodo(num);
    if (!*lst)
    {
        *lst = nuevo;
        return;
    }
    temp = *lst;
    while (temp->next)
        temp = temp->next;
    temp->next = nuevo;
}

// Imprime visualmente el estado del stack
void imprimir_stack(t_stack *lst, char nombre)
{
    printf("Stack %c: ", nombre);
    while (lst)
    {
        printf("%d -> ", lst->num);
        lst = lst->next;
    }
    printf("NULL\n");
}

// Libera la memoria al final
void liberar_stack(t_stack *lst)
{
    t_stack *temp;
    while (lst)
    {
        temp = lst;
        lst = lst->next;
        free(temp);
    }
}

// --- PROGRAMA PRINCIPAL ---

int main(void)
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;
    
    // Inicializamos todos los contadores a 0 con esta sintaxis
    t_inst_count bench = {0}; 

    // Array de prueba: ¡Cambia estos números para probar distintos escenarios!
    int nums_prueba[] = {4, 67, 3, 87, 23};
    int num_elementos = sizeof(nums_prueba) / sizeof(nums_prueba[0]);

    // Llenamos el stack A simulando la entrada del programa
    for (int i = 0; i < num_elementos; i++)
    {
        agregar_nodo_atras(&stack_a, nums_prueba[i]);
    }

    printf("--- ANTES DE ORDENAR ---\n");
    imprimir_stack(stack_a, 'A');
    imprimir_stack(stack_b, 'B');
    
    printf("\n--- EJECUTANDO SIMPLE SORT ---\n");
    
    // Llamamos a tu algoritmo
    simple_sort(&stack_a, &stack_b, &bench);

    printf("\n--- DESPUÉS DE ORDENAR ---\n");
    imprimir_stack(stack_a, 'A');
    imprimir_stack(stack_b, 'B');

    // Mostramos las estadísticas simulando el modo --bench
    printf("\n--- BENCHMARK ---\n");
    printf("Operaciones pa:  %d\n", bench.pa);
    printf("Operaciones pb:  %d\n", bench.pb);
    printf("Operaciones ra:  %d\n", bench.ra);
    printf("Operaciones rra: %d\n", bench.rra);
    printf("Total ops:       %d\n", bench.pa + bench.pb + bench.ra + bench.rra);

    // Como dictan las normas, no se permiten leaks de memoria [cite: 33]
    // Liberamos los stacks antes de salir
    liberar_stack(stack_a);
    liberar_stack(stack_b);

    return (0);
}
