int get_seed ( );
int i4_max ( int i1, int i2 );
int i4_min ( int i1, int i2 );
int i4_uniform ( int ilo, int ihi, int *seed );
void latin_random ( int dim_num, int point_num, int *seed, double x[] );
int *perm_uniform ( int n, int base, int *seed );
float r4_abs ( float x );
int r4_nint ( float x );
double r8_uniform_01 ( int *seed );
void r8mat_write ( string output_filename, int m, int n, double table[] );
void timestamp ( );


