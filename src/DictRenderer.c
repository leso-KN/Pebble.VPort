#include <pebble.h>

static GContext *rf;
static BitmapLayer *o_frame;

static void RenderDict(DictionaryIterator *dict) {
  graphics_context_set_stroke_color(rf,GColorBlack);
  GCornerMask cm;
  graphics_fill_rect(rf,GRect(0,0,144,168),0,cm);
  graphics_context_set_stroke_color(rf,GColorClear);
  Tuple *kv = dict_read_first(dict);
  for (int y=1; y<168; y++) {
    for (int x=1; x<144; x++) {
      if ((int)kv->value==1) {
        graphics_draw_pixel(rf, GPoint(x,y));
      }
    }
  }
}