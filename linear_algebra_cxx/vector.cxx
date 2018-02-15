
#include "linear_algebra.hxx"

#include <stdlib.h>
#include <stdio.h>

// ----------------------------------------------------------------------
// vector_create
//
// create a new vector of length "n"

struct vector *
vector_create(int n)
{
  vector *v = new vector;
  v->n = n;
  v->vals = (double *) calloc(n, sizeof(*v->vals));

  return v;
}

// ----------------------------------------------------------------------
// vector_create_and_set
//
// create a new vector of length "n", and set the values from "vals"

struct vector *
vector_create_and_set(int n, const double *vals)
{
  struct vector *v = vector_create(n);

  for (int i = 0; i < v->n; i++) {
    VEC(v, i) = vals[i];
  }

  return v;
}

// ----------------------------------------------------------------------
// vector_destroy
//
// destroys (deallocates) the vector "v"

void
vector_destroy(struct vector *v)
{
  free(v->vals);
  delete v;
}

// ----------------------------------------------------------------------
// vector_is_equal

bool
vector_is_equal(const struct vector *x, const struct vector *y)
{
  for (int i = 0; i < x->n; i++) {
    if (VEC(x, i) != VEC(y, i)) {
      return false;
    }
  }
  return true;
}

// vector_print
//
// prints vector "v" to stdout

void
vector_print(struct vector *v)
{
  printf("[(#=%d)", v->n);
  for (int i = 0; i < v->n; i++) {
    printf(" %g", VEC(v, i));
  }
  printf("]");
}
