### examples using style presets
<p align="center">
  <img src="https://i.imgur.com/ngOWYoZ.png" alt="1" width="45%"/>
  <img src="https://i.imgur.com/WYPowyw.png" alt="2" width="45%"/>
  <img src="https://i.imgur.com/4SkVdrP.png" alt="3" width="45%"/>
</p>

### zdraw (rendering)
- 2d primitives (lines, rectangles, circles, polygons, etc)
- text rendering with custom font support (via stb_truetype)
- texture loading and rendering
- efficient batched rendering with dynamic buffers
- clip rect support

### zui (gui)
- immediate mode gui system built on zdraw
- widgets: checkbox, button, slider, keybind, combo box (more coming)
- window management with drag/resize support
- nested windows and group boxes
- styling system with color presets
- animations and hover effects

### dependencies
- directx11
- stb_truetype
- stb_image
