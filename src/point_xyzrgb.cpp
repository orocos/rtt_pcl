/******************************************************************************
 *  Copyright (c) 2017, Intermodalics BVBA                                    *
 *  All rights reserved.                                                      *
 ******************************************************************************/

#include <rtt_pcl/typekit/Types.hpp>

// pcl::PointCloud<pcl::PointXYZRGB>
template class RTT::internal::DataSource< pcl::PointCloud<pcl::PointXYZRGB> >;
template class RTT::internal::AssignableDataSource< pcl::PointCloud<pcl::PointXYZRGB> >;
template class RTT::internal::AssignCommand< pcl::PointCloud<pcl::PointXYZRGB> >;
template class RTT::internal::ValueDataSource< pcl::PointCloud<pcl::PointXYZRGB> >;
template class RTT::internal::ConstantDataSource< pcl::PointCloud<pcl::PointXYZRGB> >;
template class RTT::internal::ReferenceDataSource< pcl::PointCloud<pcl::PointXYZRGB> >;
template class RTT::OutputPort< pcl::PointCloud<pcl::PointXYZRGB> >;
template class RTT::InputPort< pcl::PointCloud<pcl::PointXYZRGB> >;
template class RTT::Property< pcl::PointCloud<pcl::PointXYZRGB> >;
template class RTT::Attribute< pcl::PointCloud<pcl::PointXYZRGB> >;
template class RTT::Constant< pcl::PointCloud<pcl::PointXYZRGB> >;
