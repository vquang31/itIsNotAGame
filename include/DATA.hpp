#pragma once

#include <SFML/Graphics.hpp>
#include <array>

const int TIME_SPAWN = 5000;  // MILLISECONDS

const int TIME_DIE = 2000 ; // 240 ? //

const int FRAME_DIE = 6;  //

//const int TIME_DELAY = 500;

// < time_die // thoiwf gian cuar set
const int TIME_NORMAL_CAST = 200; 

const int FRAME_NORMAL_CAST = 3; // frame của lightning


const int TIME_STORYMODE = 30 * 60 * 1000;

const int ROUND_STORY = 6;

// sky

const int FRAME_SKY = 12; /// có lẽ là 120

const int TIME_SKY  = 120 * 1000;

// player

const int TIME_CAST = 200;

const int TIME_REST = 3000;

const int TIME_REVIVE = 2000;

const int FRAME_ANIMATION = 5; /// CAST AND REST

const int REVIVE_FRAME_ANIMATION = 12;

// animation endGame

const int TIME_END_GAME_ANIMATION = 500;

const int FRAME_END_GAME_ANIMATION = 3;


const int MAX_FPS = 60; // đã đo -> MAX_FPS ~= 1400  // 16 ms / 1 frame
// nếu vượt quá thì sẽ chạy vs FPS max
// nhưng tốc độ sẽ monster sẽ chậm do công thức: quãng đường tỷ lệ nghịch với MAX_FPS

const int BEGIN_POINTS = 120;

const int INCREASE_PER_WRONG_CAST = 400;

const int DECREASE_STRESS_POINT_PER_SECOND = 100;	// SLOW

const int CONST_NORMAL = 2;							// NORMAL

const int CONST_STRESS = 5;							//  FAST

const int MAX_STRESS_POINTS = 1000;

const int INTERVAL_TIME = 800;


const int WIDTH = 1600;
const int HEIGHT = 900;
const double SCALE = 1;

// enemy


const double BASE_VELOCITY_X = -100.0f; // -100
const double BASE_VELOCITY_Y = 0.0f;

const int END_GAME_POSITION_X = 0;

const int WAVE_PER_ELITE = 3;

const int TIME_CAST_SKILL_ELITE = 2000;

const int FRAME_CAST_SKILL_ELITE = 10;

// boss

const int WAVE_PER_BOSS = 10;




const int SPELL_ID[19] = {
							100,
							10,
							1,
							200,
							110,
							101,
							20,
							11,
							2,
							300,
							210,
							201,
							120,
							111,
							102,
							30,
							21,
							12,
							3,
};
