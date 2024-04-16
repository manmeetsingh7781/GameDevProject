# To Render the Enemy Image
    - GLScene.cpp -> drawScene() -> enmsTex->bindTexture() 
    - File renamed from "./images/Monster.png" -> "./images/monster.png"

# Created Enemy classes 
    - StaticEnemy - Initilizes the enemy at random location
    - EnemyMonoDirectional- Moves enemy X or Y
    - EnemyBiDirectional - Moves evemy x and y

# In GLScene.cpp
    - Changed Enums enms[20] to type of enemies we want for ex
    - StaticEnemy enms[20]
    - EnemyMonoDirectional enms[20]
    - EnemyBiDirectional enms[20]

# Files added 
    - StaticEnemy.cpp
    - EnemyMonoDirectional.cpp
    - BiDirectionEnemy.cpp

# Changes in GLEnms.cpp
    - Added Enum for each Enemy {STATIC, MOVE_AXIS, MOVE_DIRECTIONAL}
    - Changed action from `int` to `enum` so that 
        - action = 0 -> action = STATIC

`Manmeet Singh - Completed Enemy Types all 3 - May 14, 2024`

# Merged Player with Enemies
    - Added Player Class
    - Made changes to GLScene, GLInput, GLEnums, GLTimer, main.cpp

# Added Enemies images
    - Changed the enemy's texture
    - Static, MonoDirectional, and Directional enemies could have different textures, but when trying to bind them it causes flicking and overwriting of the previous texture.

# Added Collision detection of enemies with the player
    - Added GLCheckCollision Files
    - In GLScene added radial collision detection with 3 types of enemies with the player

# Changes in 
    - GLTimer - changed variable names to what make more sense of it
    - GLEnms - changed position of float to a vector3
