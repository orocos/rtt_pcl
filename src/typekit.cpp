/******************************************************************************
 *  Copyright (c) 2017, Intermodalics BVBA                                    *
 *  All rights reserved.                                                      *
 ******************************************************************************/

#include <rtt/types/Types.hpp>
#include <rtt/types/TemplateTypeInfo.hpp>
#include <rtt/types/TypekitPlugin.hpp>

#include <rtt_pcl/typekit/Types.hpp>

namespace rtt_pcl {

using namespace RTT::types;
using namespace pcl;

class PCLTypekitPlugin : public TypekitPlugin {
public:
  virtual bool loadTypes() {
    TypeInfoRepository::shared_ptr ti = Types();

    #define _RTT_PCL_ADD_TYPE(r, data, PointT) \
      ti->addType( new TemplateTypeInfo< PointCloud<PointT> >("/pcl/PointCloud" BOOST_PP_STRINGIZE(PointT)) );
    BOOST_PP_SEQ_FOR_EACH(_RTT_PCL_ADD_TYPE, _, RTT_PCL_POINT_TYPES)
    #undef _RTT_PCL_ADD_TYPE

    return true;
  }

  virtual bool loadOperators() {
    return true;
  }

  virtual bool loadConstructors() {
    return true;
  }

  virtual bool loadGlobals() {
    return true;
  }

  virtual std::string getName() {
    return "pcl-types";
  }

};

} // namespace rtt_pcl

ORO_TYPEKIT_PLUGIN( rtt_pcl::PCLTypekitPlugin )
