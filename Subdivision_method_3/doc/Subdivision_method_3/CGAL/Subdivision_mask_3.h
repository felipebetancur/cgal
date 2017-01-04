
namespace CGAL {

/*!
\ingroup PkgSurfaceSubdivisionMethods3

A stencil determines a source neighborhood 
whose points contribute to the position of a refined point. 
The geometry mask of a stencil specifies 
the computation on the nodes of the stencil. 
`CatmullClark_mask_3` implements the geometry masks of 
Catmull-Clark subdivision on models of `MutableFaceGraph`,
such as `Polyhedron_3` and `Surface_mesh`. 

\tparam PolygonMesh must be a model of the concept `MutableFaceGraph`.
\tparam VertexPointMap must be a model of `WritablePropertyMap` with value type `Point_3`

\image html CCBorderMask.png
\image latex CCBorderMask.png

\cgalModels `PQQMask_3`

\sa `CGAL::Subdivision_method_3`

*/
  template< typename PolygonMesh, typename VertexPointMap = typename boost::property_map<PolygonMesh, vertex_point_t>::type>
class CatmullClark_mask_3 {
public:

/// \name Creation 
/// @{

/*!
Constructor. 
*/ 
    CatmullClark_mask_3(PolygonMesh&  pmesh,
                        VertexPointMap vpm = get(vertex_point, pmesh) ); 

/// @} 

/// \name Stencil functions 
/// @{

/*!

computes the Catmull-Clark face-point `pt` of the face `f`. 

*/ 
void face_node(face_descriptor f, Point_3& pt); 

/*!

computes the Catmull-Clark edge-point `pt` of the edge `e`. 

*/ 
void edge_node(halfedge_descriptor e, Point_3& pt); 

/*!

computes the Catmull-Clark vertex-point `pt` of the vertex `v`. 

*/ 
void vertex_node(vertex_descriptor v, Point_3& pt); 

/*!

computes the Catmull-Clark edge-point `ept` and the 
Catmull-Clark vertex-point `vpt` of the border edge `e`. 

*/ 
void border_node(halfedge_descriptor e, Point_3& ept, Point_3& vpt); 

/// @}

}; /* end CatmullClark_mask_3 */
} /* end namespace CGAL */

namespace CGAL {

/*!
\ingroup PkgSurfaceSubdivisionMethods3

A stencil determines a source neighborhood 
whose points contribute to the position of a refined point. 
The geometry mask of a stencil specifies 
the computation on the nodes of the stencil. 
`DooSabin_mask_3` implements the geometry masks of 
Doo-Sabin subdivision on models of `MutableFaceGraph`,
such as `Polyhedron_3` and `Surface_mesh`. 

\tparam PolygonMesh must be a model of the concept `MutableFaceGraph`.
\tparam VertexPointMap must be a model of `WritablePropertyMap` with value type `Point_3`

\image html DSCornerMask.png
\image latex DSCornerMask.png

\cgalModels `DQQMask_3`

\sa `CGAL::Subdivision_method_3`

*/
template< typename PolygonMesh, typename VertexPointMap = typename boost::property_map<PolygonMesh, vertex_point_t>::type >
class DooSabin_mask_3 {
public:

/// \name Creation 
/// @{

/*!
Constructor. 
*/ 
DooSabin_mask_3(PolygonMesh&  pmesh,
                VertexPointMap vpm = get(vertex_point, pmesh) ); 

/// @} 

/// \name Stencil functions 
/// @{

/*!

computes the Doo-Sabin point `pt` of the vertex pointed 
by the halfedge `hd`. 

*/ 
void corner_node(halfedge_descriptor hd, Point_3& pt); 

/// @}

}; /* end DooSabin_mask_3 */
} /* end namespace CGAL */

namespace CGAL {

/*!
\ingroup PkgSurfaceSubdivisionMethods3

A stencil determines a source neighborhood 
whose points contribute to the position of a refined point. 
The geometry mask of a stencil specifies 
the computation on the nodes of the stencil. 
`Loop_mask_3` implements the geometry masks of 
Loop subdivision on a triangulated model of `MutableFaceGraph`,
such as `Polyhedron_3` and `Surface_mesh`.

\tparam PolygonMesh must be a model of the concept `MutableFaceGraph`. Additionally all faces must be triangles.
\tparam VertexPointMap must be a model of `WritablePropertyMap` with value type `Point_3`

\image html LoopBorderMask.png
\image latex LoopBorderMask.png

\cgalModels `PTQMask_3`

\sa `CGAL::Subdivision_method_3`

*/
template< typename PolygonMesh, typename VertexPointMap = typename boost::property_map<PolygonMesh, vertex_point_t>::type >
class Loop_mask_3 {
public:

/// \name Creation 
/// @{

/*!
Cnstructor. 
*/ 
Loop_mask_3(PolygonMesh& pmesh,
            VertexPointMap vpm = get(vertex_point,pmesh) ); 

/// @} 

/// \name Stencil functions 
/// @{

/*!

computes the Loop edge-point `pt` of the edge `hd`. 

*/ 
void edge_node(halfedge_descriptor hd, Point_3& pt); 

/*!

computes the Loop vertex-point `pt` of the vertex `vd`. 

*/ 
void vertex_node(vertex_descriptor vd, Point_3& pt); 

/*!

computes the Loop edge-point `ept` and the 
Loop vertex-point `vpt` of the border edge `hd`. 

*/ 
void border_node(halfedge_descriptor hd, Point_3& ept, Point_3& vpt); 

/// @}

}; /* end Loop_mask_3 */
} /* end namespace CGAL */

namespace CGAL {

/*!
\ingroup PkgSurfaceSubdivisionMethods3

A stencil determines a source neighborhood 
whose points contribute to the position of a refined point. 
The geometry mask of a stencil specifies 
the computation on the nodes of the stencil. 
`Sqrt3_mask_3` implements the geometry masks of 
\f$ \sqrt{3}\f$ subdivision on a triangulated 
model of `MutableFaceGraph`,
such as `Polyhedron_3` and `Surface_mesh`. 

\tparam PolygonMesh must be a model of the concept `MutableFaceGraph`. Additionally all faces must be triangles.
\tparam VertexPointMap must be a model of `WritablePropertyMap` with value type `Point_3`

\cgalModels `Sqrt3Mask_3`

\sa `CGAL::Subdivision_method_3`

*/
template< typename PolygonMesh, typename VertexPointMap = typename boost::property_map<PolygonMesh, vertex_point_t>::type >
class Sqrt3_mask_3 {
public:

/// \name Creation 
/// @{

/*!
Constructor. 
*/ 
  Sqrt3_mask_3(PolygonMesh& pmesh,
               VertexPointMap vpm = get(vertex_point,pmesh) ); 

/// @} 

/// \name Stencil functions 
/// @{

/*!

computes the \f$ \sqrt{3}\f$ face-point `pt` of the face `fd`. 

*/ 
void face_node(face_descriptor fd, Point_3& pt); 

/*!

computes the \f$ \sqrt{3}\f$ vertex-point `pt` of the vertex `vd`. 

*/ 
void vertex_node(vertex_descriptor vd, Point& pt); 

/// @}

}; /* end Sqrt3_mask_3 */
} /* end namespace CGAL */
