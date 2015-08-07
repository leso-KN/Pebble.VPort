#include <pebble.h>
#include <DictRenderer.c>
  
static Window *s_main_window;
static GBitmap *b_splash_screen;

static void o_frame_update_proc(struct Layer *layer, GContext *ctx) {
  rf = ctx;
}

static void main_window_load(Window *window) {
  b_splash_screen = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_VPORT_SPLASH);
  o_frame = bitmap_layer_create(GRect(0, 0, 144, 168));
  bitmap_layer_set_bitmap(o_frame, b_splash_screen);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(o_frame));
}

static void main_window_unload(Window *window) {
  bitmap_layer_destroy(o_frame);
}

static void init() {
  // Create main Window element and assign to pointer
  s_main_window = window_create();
  window_set_fullscreen(s_main_window, true);
  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Show the Window on the watch, with animated=true
  window_stack_push(s_main_window, true);
}

static void deinit() {
    // Destroy Window
    window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}