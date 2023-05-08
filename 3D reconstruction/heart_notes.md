三维重建随心笔记
=====
预处理
------
### 1.提取不同光照下的不同视图；  
### 2.获取图片、腌码、深度和相机信息；  
*       图片信息（512，640）：PIL读取图片信息并归一化. 
        img = Image.open(filename)
        # scale 0~255 to 0~1
        np_img = np.array(img, dtype=np.float32) / 255.
*       腌码和深度信息（1600，1200）：PIL读取信息并通过prepare_img函数将维度变为（512，640）
        img = Image.open(filename)
        np_img = np.array(img, dtype=np.float32)
        np_img = (np_img > 10).astype(np.float32)
        np_img = self.prepare_img(np_img)
*       相机信息：包含外参矩阵（世界坐标->相机坐标）、内参矩阵（相机坐标->像素坐标）、最小深度值和深度间隔  
** 外参矩阵（4，4）  
** 内参矩阵（3，3）  
