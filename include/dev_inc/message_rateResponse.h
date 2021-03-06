// Generated by gencpp from file beginner_tutorials/message_rateResponse.msg
// DO NOT EDIT!


#ifndef BEGINNER_TUTORIALS_MESSAGE_MESSAGE_RATERESPONSE_H
#define BEGINNER_TUTORIALS_MESSAGE_MESSAGE_RATERESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace beginner_tutorials
{
template <class ContainerAllocator>
struct message_rateResponse_
{
  typedef message_rateResponse_<ContainerAllocator> Type;

  message_rateResponse_()
    : oldrate(0)  {
    }
  message_rateResponse_(const ContainerAllocator& _alloc)
    : oldrate(0)  {
  (void)_alloc;
    }



   typedef int64_t _oldrate_type;
  _oldrate_type oldrate;





  typedef boost::shared_ptr< ::beginner_tutorials::message_rateResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::beginner_tutorials::message_rateResponse_<ContainerAllocator> const> ConstPtr;

}; // struct message_rateResponse_

typedef ::beginner_tutorials::message_rateResponse_<std::allocator<void> > message_rateResponse;

typedef boost::shared_ptr< ::beginner_tutorials::message_rateResponse > message_rateResponsePtr;
typedef boost::shared_ptr< ::beginner_tutorials::message_rateResponse const> message_rateResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::beginner_tutorials::message_rateResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::beginner_tutorials::message_rateResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace beginner_tutorials

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::beginner_tutorials::message_rateResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::beginner_tutorials::message_rateResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::beginner_tutorials::message_rateResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::beginner_tutorials::message_rateResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::beginner_tutorials::message_rateResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::beginner_tutorials::message_rateResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::beginner_tutorials::message_rateResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8c9d8bcd413925fb7eee642ce64d52a6";
  }

  static const char* value(const ::beginner_tutorials::message_rateResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8c9d8bcd413925fbULL;
  static const uint64_t static_value2 = 0x7eee642ce64d52a6ULL;
};

template<class ContainerAllocator>
struct DataType< ::beginner_tutorials::message_rateResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "beginner_tutorials/message_rateResponse";
  }

  static const char* value(const ::beginner_tutorials::message_rateResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::beginner_tutorials::message_rateResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 oldrate\n\
";
  }

  static const char* value(const ::beginner_tutorials::message_rateResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::beginner_tutorials::message_rateResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.oldrate);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct message_rateResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::beginner_tutorials::message_rateResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::beginner_tutorials::message_rateResponse_<ContainerAllocator>& v)
  {
    s << indent << "oldrate: ";
    Printer<int64_t>::stream(s, indent + "  ", v.oldrate);
  }
};

} // namespace message_operations
} // namespace ros

#endif // BEGINNER_TUTORIALS_MESSAGE_MESSAGE_RATERESPONSE_H
