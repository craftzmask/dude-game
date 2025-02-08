/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	xDist(0.0f, 770.0f),
	yDist(0.0f, 570.0f),
	goal(Vec2(xDist(rng), yDist(rng))),
	meter(20, 20),
	dudeSprite("awsom.bmp"),
	pooSprite("poo.bmp"),
	dude(dudeSprite)
{	
	std::uniform_real_distribution<float> v(-2.5f * 60.0f, 2.5f * 60.0f);
	poos.reserve(nPoos);
	for (int i = 0; i < nPoos; ++i)
	{
		poos.emplace_back(Vec2(xDist(rng), yDist(rng)), Vec2(v(rng), v(rng)), pooSprite);
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.Mark();

	goal.UpdateColor();
	if (isStarted && !isGameOver)
	{
		dude.Update(wnd.mouse, dt);
		if (goal.TestCollision(dude))
		{
			meter.IncreaseLevel();
			goal.Respawn(Vec2(xDist(rng), yDist(rng)));
		}

		for (int i = 0; i < nPoos; ++i)
		{
			if (poos[i].TestCollision(dude))
			{
				isGameOver = true;
			}
			poos[i].Update(dt);
		}
	}
	else
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			isStarted = true;
		}
	}
}

void Game::DrawGameOver(int x, int y)
{
	gfx.DrawSpriteNonChroma(x, y, { "game_over.bmp" });
}

void Game::DrawScreenTitle(int x, int y)
{
	gfx.DrawSpriteNonChroma(x, y, { "dapoopoo.bmp" });
}

void Game::ComposeFrame()
{
	if (!isStarted)
	{
		DrawScreenTitle(270, 100);
	}
	else
	{
		if (isGameOver)
		{
			DrawGameOver(358, 268);
		}

		dude.Draw(gfx);
		goal.Draw(gfx);

		for (int i = 0; i < nPoos; ++i)
		{
			poos[i].Draw(gfx);
		}

		meter.Draw(gfx);
	}
}
