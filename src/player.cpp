#include "include/player.h"
#include "SDL_events.h"
#include "SDL_keycode.h"
#include "SDL_rect.h"
#include "SDL_render.h"
#include "imgui_impl_sdl2.h"
#include <imgui.h>

Player::Player(int x, int y) {
  // Player initial Position
  Pos_X = x;
  Pos_Y = y;
}

void Player::move(int deltaX, int deltaY) {
  // pLayer movement
  Pos_Y += deltaY;

  Pos_X += deltaX;
}

void Player::render(SDL_Renderer *renderer) const {

  SDL_Rect playerRect = {Pos_X, Pos_Y, 50, 50};
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &playerRect);

  /*   ImGui::Begin("Player");
    ImGui::SetWindowPos(ImVec2(Pos_X, Pos_Y));
    ImGui::SetWindowSize(ImVec2(50, 50));
    ImGui::Text("PLayer");
    ImGui::End(); */
}

void Player::jump(int height) { Pos_Y += height; }

int Player::getPosX() const { return Pos_X; }

int Player::getPosY() const { return Pos_Y; }

void Player::handelEvent(const SDL_Event &e) {

  if (e.type == SDL_KEYDOWN) {
    switch (e.key.keysym.sym) {
    case SDLK_w:
    case SDLK_UP:
      move(0, -10);
      break;

    case SDLK_s:
    case SDLK_DOWN:
      move(0, 10);
      break;

    case SDLK_a:
    case SDLK_LEFT:
      move(-10, 0);
      break;

    case SDLK_d:
    case SDLK_RIGHT:
      move(10, 0);
      break;
    }
  }
}
