# include <cstdlib>
# include <cmath>

using namespace std;

void boundary_type ( int node_num, double node_xy[], bool node_boundary[], 
  int node_type[], int node_u_condition[], int node_v_condition[], 
  int node_p_condition[] );
void dirichlet_condition ( int node_num, double node_xy[], double u_bc[], 
  double v_bc[], double p_bc[] );
void neumann_condition ( int node_num, double node_xy[], double u_bc[], 
  double v_bc[], double p_bc[] );
void rhs ( int node_num, double node_xy[], double u_rhs[], double v_rhs[], 
  double p_rhs[] );

//******************************************************************************

void boundary_type ( int node_num, double node_xy[], bool node_boundary[], 
  int node_type[], int node_u_condition[], int node_v_condition[], 
  int node_p_condition[] )

//******************************************************************************
//
//  Purpose:
//
//    BOUNDARY_TYPE determines the type of boundary conditions imposed.
//
//  Discussion:
//
//    On input, the calling program has already determined the "type"
//    of every node (vertex or midside), and whether or not it lies
//    on the boundary.
//
//    The program has also set up an initial guess for the boundary
//    conditions, by setting every boundary node to have Dirichlet
//    conditions for U and V, and by setting a single vertex boundary
//    node to have Dirichlet boundary conditions for P.
//
//    The user is free to adjust these boundary conditions in any
//    reasonable way.  
//
//    The most obvious adjustment is to change some velocity boundary
//    conditions to Neumann conditions.  Keep in mind that, for the moment, 
//    we are only supporting zero Neumann conditions.
//
//    However, it is also possible to constrain ANY variable, whether it
//    is on the boundary or not, or to UNCONSTRAIN any variable that
//    has been tentatively constrained.  You simply have to "warn" the code,
//    by setting U_TYPE, V_TYPE or P_TYPE appropriately, and by supplying
//    a value for the right hand side if you are doing a Dirichlet condition.
//
//
//    For the cavity flow, we intend for the Dirichlet boundary conditions 
//    to be applied for velocity at all boundary points. 
//
//    The calling program has already found the boundary, and guessed that
//    all boundary velocities are constrained by Dirichlet conditions.  So
//    this routine has nothing to do//
//
//
//    The pressure is specified to be zero at a single node, but we let
//    the main program take care of that specification.
//
//                           Dirichlet
//                           U = 1  V = 0
//
//                       1 +--> --> --> -->+
//                         |               |
//                         |               |
//            Dirichlet    |               |  Dirichlet
//            U = V = 0    |               |  U = V = 0
//                         |               |
//                         |               |
//                         |               |
//                       0 +---------------+
//
//                         0               1
//
//                            Dirichlet
//                            U = V = 0
//
//  Modified:
//
//    07 October 2006
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int NODE_NUM, the number of nodes
//
//    Input, double NODE_XY[2*NODE_NUM], the coordinates of the nodes.
//
//    Input, bool NODE_BOUNDARY[NODE_NUM], is TRUE if the node is
//    found to lie on the boundary of the region.
//
//    Input, int NODE_TYPE[NODE_NUM], determines if the node is a 
//    vertex or midside node.
//    1, the node is a vertex (P, U, V variables are associated with it).
//    2, the node is a midside node (only U and V variables are associated.)
//
//    Input/output, int NODE_U_CONDITION[NODE_NUM], 
//    indicates the condition used to determine horizontal velocity at a node.
//    0, there is no condition (and no variable) at this node.
//    1, a finite element equation is used;
//    2, a Dirichlet condition is used. 
//    3, a Neumann condition is used. 
//
//    Input/output, int NODE_V_CONDITION[NODE_NUM], 
//    indicates the condition used to determine vertical velocity at a node.
//    0, there is no condition (and no variable) at this node.
//    1, a finite element equation is used;
//    2, a Dirichlet condition is used.
//    3, a Neumann condition is used.  
//
//    Input/output, int NODE_P_CONDITION[NODE_NUM], 
//    indicates the condition used to determine pressure at a node.
//    0, there is no condition (and no variable) at this node.
//    1, a finite element equation is used;
//    2, a Dirichlet condition is used. 
//    3, a Neumann condition is used. 
//
{
  return;
}
//******************************************************************************

void dirichlet_condition ( int node_num, double node_xy[], double u_bc[], 
  double v_bc[], double p_bc[] )

//******************************************************************************
//
//  Purpose:
//
//    DIRICHLET_CONDITION sets the value of a Dirichlet boundary condition.
//
//  Discussion:
//
//                           Dirichlet
//                           U = 1  V = 0
//
//                       1 +--> --> --> -->+
//                         |               |
//                         |               |
//            Dirichlet    |               |  Dirichlet
//            U = V = 0    |               |  U = V = 0
//                         |               |
//                         |               |
//                         |               |
//                       0 +---------------+
//
//                         0               1
//
//                            Dirichlet
//                            U = V = 0
//
//  Modified:
//
//    08 October 2006
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int NODE_NUM, the number of nodes.
//
//    Input, double NODE_XY[2*NODE_NUM], the coordinates of the nodes.
//
//    Output, double U_BC[NODE_NUM], V_BC[NODE_NUM], P_BC[NODE_NUM], the 
//    values of the Dirichlet boundary conditions on horizontal velocity, 
//    vertical velocity, and pressure.
//
{
  int node;
  double tol = 0.0001;
  double x;
  double y;

  for ( node = 0; node < node_num; node++ )
  {
    x = node_xy[0+node*2];
    y = node_xy[1+node*2];

    if ( fabs ( y - 1.0 ) <= tol )
    {
      u_bc[node] = 1.0;
    }
    else
    {
      u_bc[node] = 0.0;
    }

    v_bc[node] = 0.0;
    p_bc[node] = 0.0;
  }

  return;
}
//******************************************************************************

void neumann_condition ( int node_num, double node_xy[], double u_bc[], 
  double v_bc[], double p_bc[] )

//*******************************************************************************
//
//  Purpose:
//
//    NEUMANN_CONDITION sets the value of any Neumann boundary conditions.
//
//  Discussion:
//
//    Note that, at the moment, we are simply trying to implement
//    ZERO Neumann boundary conditions, and are not ready to try
//    to implement the NONZERO case.  Therefore, setting nonzero values
//    here is unlikely to work for some time//
//
//
//    Neumann boundary conditions might be applied to none, some, or
//    all the boundary nodes, and might apply to any combination of
//    U, V, and P.
//
//    This routine will be asked to supply a right hand side for the
//    Neumann conditions for U, V and P at EVERY node.  Simply set
//    the value to zero for nodes and variables at which a Neumann
//    condition is not being applied.  But set an appropriate value
//    to U_BC, V_BC or P_BC in cases where a Neumann condition is
//    being applied for that degree of freedom at that node.
//
//
//    For the cavity flow, there are no Neumann conditions, so this
//    routine has nothing to do!
//
//                           Dirichlet
//                           U = 1  V = 0
//
//                       1 +--> --> --> -->+
//                         |               |
//                         |               |
//            Dirichlet    |               |  Dirichlet
//            U = V = 0    |               |  U = V = 0
//                         |               |
//                         |               |
//                         |               |
//                       0 +---------------+
//
//                         0               1
//
//                            Dirichlet
//                            U = V = 0
//
//  Modified:
//
//    08 October 2006
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int NODE_NUM, the number of nodes.
//
//    Input, double NODE_XY[2*NODE_NUM], the coordinates of the nodes.
//
//    Output, double U_BC[NODE_NUM], V_BC[NODE_NUM], P_BC[NODE_NUM],
//    the values of the boundary conditions on horizontal velocity, 
//    vertical velocity, and pressure.
//
{
  int node;

  for ( node = 0; node < node_num; node++ )
  {
    u_bc[node] = 0.0;
    v_bc[node] = 0.0;
    p_bc[node] = 0.0;
  }

  return;
}
//******************************************************************************

void rhs ( int node_num, double node_xy[], double u_rhs[], double v_rhs[], 
  double p_rhs[] )

//******************************************************************************
//
//  Purpose:
//
//    RHS gives the right-hand side of the differential equation.
//
//  Modified:
//
//    08 October 2006
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int NODE_NUM, the number of points.
//
//    Input, double NODE_XY[2*NODE_NUM], the coordinates of the points.
//
//    Output, double U_RHS[NODE_NUM], V_RHS[NODE_NUM], P_RHS[NODE_NUM], 
//    the right hand sides of the differential equations at the points.
//
{
  int node;

  for ( node = 0; node < node_num; node++ )
  {
    p_rhs[node] = 0.0;
    u_rhs[node] = 0.0;
    v_rhs[node] = 0.0;
  }

  return;
}
