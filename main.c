#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#define GRUVBOX_BG (Color){29, 32, 33, 255}
#define GRUVBOX_FG (Color){235, 219, 178, 255}
#define GRUVBOX_YELLOW (Color){250, 189, 47, 255}
#define GRUVBOX_ORANGE (Color){254, 128, 25, 255}
#define GRUVBOX_RED (Color){251, 73, 52, 255}
#define GRUVBOX_GREEN (Color){184, 187, 38, 255}
int main() {
  InitWindow(200, 160, "shutthhisdown");
  SetTargetFPS(60);
  SetWindowOpacity(0.5);

  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, ColorToInt(GRUVBOX_FG));
  GuiSetStyle(DEFAULT, BASE_COLOR_NORMAL, ColorToInt(GRUVBOX_BG));
  GuiSetStyle(DEFAULT, BORDER_COLOR_NORMAL, ColorToInt(GRUVBOX_GREEN));

  GuiSetStyle(DEFAULT, BASE_COLOR_FOCUSED, ColorToInt(GRUVBOX_YELLOW));
  GuiSetStyle(DEFAULT, TEXT_COLOR_FOCUSED, ColorToInt(GRUVBOX_BG));

  GuiSetStyle(DEFAULT, BASE_COLOR_PRESSED, ColorToInt(GRUVBOX_RED));
  GuiSetStyle(DEFAULT, TEXT_COLOR_PRESSED, ColorToInt(GRUVBOX_BG));

  int focus = 0;
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GRUVBOX_BG);

    if (IsKeyPressed(KEY_TAB)) {
      focus = (focus + 1) % 3;
    }
    if (IsKeyPressed(KEY_ENTER)) {
      if (focus == 0) {
        goto close;
      } else if (focus == 1) {
        system("shutdown -h now");
      } else if (focus == 2) {
        system("shutdown -r now");
      }
    }

    if (GuiButton((Rectangle){50, 10, 100, 40},
                  focus == 0 ? "#01#Nothing" : "Nothing")) {
      goto close;
    }

    if (GuiButton((Rectangle){50, 60, 100, 40},
                  focus == 1 ? "#01#Shutdown" : "Shutdown")) {
      system("shutdown -h now");
    }

    if (GuiButton((Rectangle){50, 110, 100, 40},
                  focus == 2 ? "#01#Restart" : "Restart")) {
      system("shutdown -r now");
    }

    EndDrawing();
  }

close:
  CloseWindow();
  return 0;
}
