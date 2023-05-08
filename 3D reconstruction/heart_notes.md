三维重建随心笔记
=====
预处理
------
### 1.提取不同光照下的不同视图；  
### 2.获取图片、腌码、深度和相机信息；  
* 图片信息（512，640）：PIL读取图片信息并归一化. 

```
img = Image.open(filename)
img = np.array(img, dtype=np.float32) / 255  # scale 0~255 to 0~1
...
imgs.append(img) #all images
return imgs
```

* 腌码和深度信息（1600，1200）：PIL读取信息并通过prepare_img函数将维度变为（512，640）

```
# read_inforamtion
img = Image.open(filename)
np_img = np.array(img, dtype=np.float32)
np_img = (np_img > 10).astype(np.float32)
np_img = self.prepare_img(np_img)

# prepare_img
h, w = hr_img.shape  #downsample
hr_img_ds = cv2.resize(hr_img, (w//2, h//2), interpolation=cv2.INTER_NEAREST)
h, w = hr_img_ds.shape
target_h, target_w = 512, 640
start_h, start_w = (h - target_h)//2, (w - target_w)//2
hr_img_crop = hr_img_ds[start_h: start_h + target_h, start_w: start_w + target_w]
...
return mask_ms, value_ms_gt
```

* 相机信息：包含外参矩阵（世界坐标->相机坐标）、内参矩阵（相机坐标->像素坐标）、最小深度值和深度间隔  
  - 外参矩阵（4，4）和内参矩阵（3，3）
  
  ```
  extrinsic  # proj_matrices[0,:4,:4]
  0.0101852 -0.915292 0.402663 -233.284
  0.0174606 0.402786 0.915128 -551.994
  -0.999796 -0.00229 0.020084 882.877
  0.0 0.0 0.0 1.0
  
  intrinsic. # proj_matrices[1,:3,:3]
  2892.33 0 823.204
  0 2883.17 619.072
  0 0 1

  425 2.5  # depth_min, depth_interval
  return proj_matrices
  ```  
  
  - 深度值
  ```
  #get depth values
  depth_max = depth_interval * self.ndepths + depth_min
  disp_min = 1 / depth_max
  disp_max = 1 / depth_min
  depth_values = np.linspace(disp_min, disp_max, self.ndepths, dtype=np.float32)
  ...
  return depth_values
  ```
