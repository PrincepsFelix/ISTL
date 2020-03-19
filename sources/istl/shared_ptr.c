/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/shared_ptr.h"

void *shared_ptr(mdata_t tmeta)
{
    void *alloc = snew(tmeta);
    mcell_t *mcell = get_mcell(&alloc);

    mcell->type = SP_SHARED;
    mcell->wcount = malloc(sizeof(uint_t));
    mcell->count = malloc(sizeof(uint_t));
    *mcell->count = 1;
    *mcell->wcount = 0;
    return (mcell->data);
}

void *spcopy(void *ptr)
{
    mcell_t *mcell = get_mcell(&ptr);

    if (mcell->data != ptr)
        return (NULL);
    *mcell->count += 1;
    return (mcell->data);
}

uint_t ref_count(void *ptr)
{
    mcell_t *mcell = get_mcell(&ptr);

    if (ptr == NULL || ptr != mcell->data)
        return (0);
    if (mcell->count != NULL)
        return (*mcell->count);
    return (0);
}
