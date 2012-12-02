int b4set_colex_rank ( int n, int t );
void b4set_colex_successor ( int n, int &t, int &rank );
int b4set_colex_unrank ( int rank, int n );
int b4set_complement ( int n, int a );
int b4set_complement_relative ( int n, int a, int b );
int b4set_delete ( int n, int a, int t );
int b4set_distance ( int n, int t1, int t2 );
int b4set_enum ( int n );
int b4set_index ( int n, int a, int t );
int b4set_insert ( int n, int a, int t );
int b4set_intersect ( int n, int a, int b );
bool b4set_is_empty ( int n, int t );
bool b4set_is_equal ( int n, int t1, int t2 );
bool b4set_is_member ( int n, int a, int t );
bool b4set_is_subset ( int n, int t1, int t2 );
int b4set_lex_rank ( int n, int t );
void b4set_lex_successor ( int n, int &t, int &rank );
int b4set_lex_unrank ( int rank, int n );
int b4set_random ( int n, int &seed );
bool *b4set_to_lset ( int n, int t );
void b4set_transpose_print ( int n, int t, string title );
int b4set_union ( int n, int a, int b );
int b4set_weight ( int n, int t );
int b4set_xor ( int n, int a, int b );
char digit_to_ch ( int i );
int i4_bclr ( int i, int p );
int i4_bset ( int i, int p );
bool i4_btest ( int i, int p );
int i4_log_10 ( int i );
int i4_max ( int i1, int i2 );
int i4_min ( int i1, int i2 );
int i4_power ( int i, int j );
string i4_to_s ( int i );
int i4_width ( int i );
int i4_xor ( int i, int p );
int i4vec_to_b4set ( int n_num, int a_num[], int n );
bool *i4vec_to_lset ( int n_num, int a_num[], int n );
int *i4vec_uniform_new ( int n, int a, int b, int &seed );
int lset_colex_rank ( int n, bool t[] );
void lset_colex_successor ( int n, bool t[], int &rank );
bool *lset_colex_unrank ( int rank, int n );
bool *lset_complement ( int n, bool a[] );
bool *lset_complement_relative ( int n, bool a[], bool b[] );
void lset_delete ( int n, int a, bool t[] );
int lset_distance ( int n, bool t1[], int t2[] );
int lset_enum ( int n );
int lset_index ( int n, int a, bool t[] );
void lset_insert ( int n, int a, bool t[] );
bool *lset_intersect ( int n, bool a[], bool b[] );
bool lset_is_empty ( int n, bool t[] );
bool lset_is_equal ( int n, bool t1[], bool t2[] );
bool lset_is_member ( int n, int a, bool t[] );
bool lset_is_subset ( int n, bool t1[], bool t2[] );
int lset_lex_rank ( int n, bool t[] );
void lset_lex_successor ( int n, bool t[], int &rank );
bool *lset_lex_unrank ( int rank, int n );
bool *lset_random ( int n, int &seed );
int lset_to_b4set ( int n, bool a_log[] );
void lset_transpose_print ( int n, bool t[], string title );
bool *lset_union ( int n, bool a[], bool b[] );
int lset_weight ( int n, bool t[] );
bool *lset_xor ( int n, bool a[], bool b[] );
void lvec_transpose_print ( int n, bool t[], string title );
int r4_nint ( float x );
void timestamp ( );
