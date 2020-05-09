#pragma once

const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 800;
const int NUM_OF_LANES = 3;
const float SPAWN_COOLDOWN = 3.0f;
const float SPEED = 35.0f;

const float TOP_BORDER = 110.0f;
const float BOTTOM_BORDER = 670.0f;
const float LEFT_BORDER = 40.0f;
const float RIGHT_BORDER = 440.0f;
const float DIVIDE_LINE_1 = 174.0f;
const float DIVIDE_LINE_2 = 306.0f;
const float SCORE_PADDING_MASK = 5.0f;

const float OBJECT_PADDING_BIG = 12.0f;
const float OBJECT_PADDING_MEDIUM = 9.0f;
const float OBJECT_PADDING_SMALL = 6.0f;

const float SPAWN_AREA_HEIGHT = 65.0f;

const int SCORE_MULTIPLIER = 2;

const float COUNTDOWN_BAR_MARGIN = 15.0f;
const float COUNTDOWN_BAR_HEIGHT = 10.0f;
const float COUNTDOWN_BAR_WIDTH = 60.0f;

const float ICON_POSITION_PADDING = 50.0f;

enum MinionType : int
{
	Bot,
	Player
};

enum MinionWeight : int
{
	Small = 1,
	Medium = 2,
	Big = 3
};