#pragma once

typedef struct {
  int min;
  int max;
} ReturnParam;

ReturnParam get_arguments(int argc, char *argv[]);