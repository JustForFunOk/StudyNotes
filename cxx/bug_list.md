# bug

## 1

``` bash
In file included from /home/sunjian/workspace/research-platform/ad/tool/utility/rviz/sensor_fov_visualizer/src/sensor_fov_visualizer.cpp:1:0:
/home/sunjian/workspace/research-platform/ad/tool/utility/rviz/sensor_fov_visualizer/include/sensor_fov_visualizer.h: In constructor ‘svw::rviz::SensorFovVisualizer::SensorFovVisualizer()’:
/home/sunjian/workspace/research-platform/ad/tool/utility/rviz/sensor_fov_visualizer/include/sensor_fov_visualizer.h:54:17: error: ‘svw::rviz::SensorFovVisualizer::frame_id_’ will be initialized after [-Werror=reorder]
     std::string frame_id_;
                 ^
/home/sunjian/workspace/research-platform/ad/tool/utility/rviz/sensor_fov_visualizer/include/sensor_fov_visualizer.h:47:22: error:   ‘Ogre::SceneNode* svw::rviz::SensorFovVisualizer::scene_node_’ [-Werror=reorder]
     Ogre::SceneNode* scene_node_;
                      ^
/home/sunjian/workspace/research-platform/ad/tool/utility/rviz/sensor_fov_visualizer/src/sensor_fov_visualizer.cpp:15:1: error:   when initialized here [-Werror=reorder]
 SensorFovVisualizer::SensorFovVisualizer() : frame_id_("ego_vehicle_rear_axis"), scene_node_(nullptr)

```
初始化列表顺序

## 2

``` c++
object_distance_m = std::static_cast< float >(_object_distance_cm) / 100;  // cm 2 m
```
``` bug
error: expected unqualified-id before ‘static_cast’
```
remove `std::`