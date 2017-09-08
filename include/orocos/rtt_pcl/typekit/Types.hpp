/******************************************************************************
 *  Copyright (c) 2017, Intermodalics BVBA                                    *
 *  All rights reserved.                                                      *
 ******************************************************************************/

#ifndef RTT_PCL_TYPEKIT_TYPES_HPP
#define RTT_PCL_TYPEKIT_TYPES_HPP

#include <rtt/internal/DataSources.hpp>
#include <rtt/internal/AssignCommand.hpp>
#include <rtt/OutputPort.hpp>
#include <rtt/InputPort.hpp>
#include <rtt/Property.hpp>
#include <rtt/Attribute.hpp>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <boost/preprocessor.hpp>

#define RTT_PCL_POINT_TYPES \
  (PointXYZ) \
  (PointXYZRGB) \
  (PointXYZRGBNormal)

#define _RTT_PCL_EXTERN_TEMPLATE_DECLARATION(r, data, PointT) \
  extern template class RTT::internal::DataSource< pcl::PointCloud<pcl::PointT> >; \
  extern template class RTT::internal::AssignableDataSource< pcl::PointCloud<pcl::PointT> >; \
  extern template class RTT::internal::AssignCommand< pcl::PointCloud<pcl::PointT> >; \
  extern template class RTT::internal::ValueDataSource< pcl::PointCloud<pcl::PointT> >; \
  extern template class RTT::internal::ConstantDataSource< pcl::PointCloud<pcl::PointT> >; \
  extern template class RTT::internal::ReferenceDataSource< pcl::PointCloud<pcl::PointT> >; \
  extern template class RTT::OutputPort< pcl::PointCloud<pcl::PointT> >; \
  extern template class RTT::InputPort< pcl::PointCloud<pcl::PointT> >; \
  extern template class RTT::Property< pcl::PointCloud<pcl::PointT> >; \
  extern template class RTT::Attribute< pcl::PointCloud<pcl::PointT> >; \
  extern template class RTT::Constant< pcl::PointCloud<pcl::PointT> >; \

BOOST_PP_SEQ_FOR_EACH(_RTT_PCL_EXTERN_TEMPLATE_DECLARATION, _, RTT_PCL_POINT_TYPES)

#undef _RTT_PCL_EXTERN_TEMPLATE_DECLARATION

#endif // RTT_PCL_TYPEKIT_TYPES_HPP
