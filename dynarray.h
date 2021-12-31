#ifndef __DYNARRAY_H
#define __DYNARRAY_H

struct dynarray;

struct dynarray* dynarray_create();
void dynarray_free(struct dynarray* da);
int dynarray_size(struct dynarray* da);
void dynarray_insert(struct dynarray* da, void* val);
void* dynarray_remove(struct dynarray* da, int idx);
void* dynarray_get(struct dynarray* da, int idx);
void dynarray_set(struct dynarray* da, int idx, void* val);
int get_start(struct dynarray* da);
int get_back(struct dynarray* da);


#endif
