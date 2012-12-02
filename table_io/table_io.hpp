char ch_cap ( char c );
bool ch_eqi ( char c1, char c2 );
int ch_to_digit ( char c );
int file_column_count ( string input_filename );
int file_row_count ( string input_filename );
int i4_log_10 ( int i );
int i4_max ( int i1, int i2 );
int i4_min ( int i1, int i2 );
int *i4mat_indicator_new ( int m, int n );
void i4mat_print ( int m, int n, int a[], string title );
void i4mat_print_some ( int m, int n, int a[], int ilo, int jlo, int ihi, 
  int jhi, string title );
int *i4mat_border_add ( int m, int n, int table[] );
int *i4mat_border_cut ( int m, int n, int table[] );
int *i4mat_data_read ( string input_filename, int m, int n );
void i4mat_header_read ( string input_filename, int *m, int *n );
int *i4mat_read ( string input_filename, int *m, int *n );
void i4mat_write ( string output_filename, int m, int n, int table[] );
bool *lvec_data_read ( string input_filename, int n );
void lvec_header_read ( string input_filename, int *n );
void lvec_write ( string output_filename, int n, bool table[] );
float *r4mat_data_read ( string input_filename, int m, int n );
void r4mat_header_read ( string input_filename, int *m, int *n );
float *r4mat_indicator_new ( int m, int n );
void r4mat_print ( int m, int n, float a[], string title );
void r4mat_print_some ( int m, int n, float a[], int ilo, int jlo, int ihi, 
  int jhi, string title );
float *r4mat_read ( string input_filename, int *m, int *n );
void r4mat_transpose_print ( int m, int n, float a[], string title );
void r4mat_transpose_print_some ( int m, int n, float a[], int ilo, int jlo, 
  int ihi, int jhi, string title );
float *r4mat_uniform_01 ( int m, int n, int *seed );
void r4mat_write (string output_filename, int m, int n, float table[] );
double *r8mat_border_add ( int m, int n, double table[] );
double *r8mat_border_cut ( int m, int n, double table[] );
double *r8mat_data_read ( string input_filename, int m, int n );
void r8mat_header_read ( string input_filename, int *m, int *n );
double *r8mat_indicator_new ( int m, int n );
void r8mat_print ( int m, int n, double a[], string title );
void r8mat_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi, 
  int jhi, string title );
double *r8mat_read ( string input_filename, int *m, int *n );
void r8mat_transpose_print ( int m, int n, double a[], string title );
void r8mat_transpose_print_some ( int m, int n, double a[], int ilo, int jlo, 
  int ihi, int jhi, string title );
double *r8mat_uniform_01 ( int m, int n, int *seed );
void r8mat_write (string output_filename, int m, int n, double table[] );
double *r8vec_data_read ( string input_filename, int n );
void r8vec_header_read ( string input_filename, int *n );
void r8vec_write (string output_filename, int n, double x[] );
void r8vec2_write (string output_filename, int n, double x[], double y[] );
int s_len_trim ( string s );
int s_to_i4 ( string s, int *last, bool *error );
bool s_to_i4vec ( string s, int n, int ivec[] );
bool s_to_l ( string s );
float s_to_r4 ( string s, int *lchar, bool *error );
bool s_to_r4vec ( string s, int n, float rvec[] );
double s_to_r8 ( string s, int *lchar, bool *error );
bool s_to_r8vec ( string s, int n, double rvec[] );
int s_word_count ( string s );
void timestamp ( );
