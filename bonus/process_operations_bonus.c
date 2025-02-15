#include "../includes/checker_bonus.h"

t_instruction    *new_instruction(char *operation)
{
    t_instruction    *new;

    new = malloc(sizeof(t_instruction));
    if (!new)
        return (NULL);
    new->operation = ft_strdup(operation);
    if (!new->operation)
    {
        free(new);
        return (NULL);
    }
    new->next = NULL;
    return (new);
}

static t_instruction    *read_instructions(void)
{
    t_instruction    *head;
    t_instruction    *current;
    char            *line;

    head = NULL;
    current = NULL;
    while ((line = get_next_line(0)))
    {
        if (!is_valid_instruction(line))
        {
            free(line);
            free_instructions(head);
            return (NULL);
        }
        if (!head)
        {
            head = new_instruction(line);
            current = head;
        }
        else
        {
            current->next = new_instruction(line);
            current = current->next;
        }
        if (!current)
        {
            free(line);
            free_instructions(head);
            return (NULL);
        }
        free(line);
    }
    return (head);
}

void    process_operations(t_stack *a, t_stack *b)
{
    t_instruction    *instructions;
    t_instruction    *current;

    instructions = read_instructions();
    if (!instructions)
        clean_exit(a, b);
    current = instructions;
    while (current)
    {
        if (!execute_operation(a, b, current->operation))
        {
            free_instructions(instructions);
            clean_exit(a, b);
        }
        current = current->next;
    }
    free_instructions(instructions);
}

int    execute_operation(t_stack *a, t_stack *b, char *op)
{
    if (ft_strncmp(op, "sa\n", 3) == 0)
        sa(a);
    else if (ft_strncmp(op, "sb\n", 3) == 0)
        sb(b);
    else if (ft_strncmp(op, "ss\n", 3) == 0)
        ss(a, b);
    else if (ft_strncmp(op, "pa\n", 3) == 0)
        pa(a, b);
    else if (ft_strncmp(op, "pb\n", 3) == 0)
        pb(a, b);
    else if (ft_strncmp(op, "ra\n", 3) == 0)
        ra(a);
    else if (ft_strncmp(op, "rb\n", 3) == 0)
        rb(b);
    else if (ft_strncmp(op, "rr\n", 3) == 0)
        rr(a, b);
    else if (ft_strncmp(op, "rra\n", 4) == 0)
        rra(a);
    else if (ft_strncmp(op, "rrb\n", 4) == 0)
        rrb(b);
    else if (ft_strncmp(op, "rrr\n", 4) == 0)
        rrr(a, b);
    else
        return (0);
    return (1);
}

