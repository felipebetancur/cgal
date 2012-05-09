// Copyright (c) 2012 INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org).
// You can redistribute it and/or modify it under the terms of the GNU
// General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://sloriot@scm.gforge.inria.fr/svn/cgal/branches/features/AABB_tree-one_primitive_per_object-sloriot/AABB_tree/include/CGAL/AABB_triangle_primitive.h $
// $Id: AABB_triangle_primitive.h 68959 2012-05-04 12:24:50Z sloriot $
//
//
// Author(s)     : Sebastien Loriot
//
//******************************************************************************
// File Description :
//
//******************************************************************************

#ifndef CGAL_AABB_HALFEDGEGRAPH_TRIANGLE_PRIMITIVE_H
#define CGAL_AABB_HALFEDGEGRAPH_TRIANGLE_PRIMITIVE_H

#include <CGAL/AABB_primitive.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/Polyhedron_3_property_map.h>

#include <iterator>
#include <boost/mpl/and.hpp>
#include <CGAL/is_iterator.h>
#include <boost/type_traits/is_convertible.hpp>
#include <boost/utility/enable_if.hpp>

namespace CGAL {

  
template < class HalfedgeGraph,
           class cache_primitive=Tag_false,
           class Id_=typename HalfedgeGraph::Halfedge_handle //this one should be autodetected using edge_descriptor
           >
class AABB_HalfedgeGraph_segment_primitive : public AABB_primitive< Id_,
                                                                    Segment_from_halfedge_property_map<HalfedgeGraph>,
                                                                    One_point_from_halfedge_property_map<HalfedgeGraph>,
                                                                    cache_primitive >
{
  typedef Segment_from_halfedge_property_map<HalfedgeGraph>  Triangle_property_map;
  typedef One_point_from_halfedge_property_map<HalfedgeGraph> Point_property_map;
  
  typedef AABB_primitive< Id_,
                          Triangle_property_map,
                          Point_property_map,
                          cache_primitive > Base;
  
public:
  // constructors
  AABB_HalfedgeGraph_segment_primitive(Id_ it) : Base(it){}
  template <class Iterator>
  AABB_HalfedgeGraph_segment_primitive(Iterator it,
                                       typename boost::enable_if<
                                          boost::mpl::and_<
                                            boost::integral_constant<bool, is_iterator<Iterator>::value >,
                                            boost::is_convertible<
                                              typename std::iterator_traits<Iterator>::value_type,
                                              std::pair<HalfedgeGraph*,Id_>
                                            >
                                          >
                                        >::type* = NULL )
    : Base( it->second,
            Triangle_property_map((it->first)),
            Point_property_map((it->first)) ){}
};

}  // end namespace CGAL


#endif // CGAL_AABB_HALFEDGEGRAPH_TRIANGLE_PRIMITIVE_H

