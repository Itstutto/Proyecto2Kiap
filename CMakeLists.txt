cmake_minimum_required(VERSION 4.1)
project(Proyecto2Kiap)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto2Kiap main.cpp
        Character.cpp
        Character.h
        Player.cpp
        Player.h
        Movement.h
        Enemy.cpp
        Enemy.h
        Movement.cpp
        UpperZone.cpp
        UpperZone.h
        BodyZones.h
        IShow.h
        LowerZone.cpp
        LowerZone.h
        ZonesFactory.cpp
        ZonesFactory.h
        ObjectMovement.cpp
        ObjectMovement.h
        MovementsFactory.cpp
        MovementsFactory.h
        MakeMoves.h
        MovementMaker.cpp
        MovementMaker.h
        Vectors.h
        LowerMovList.cpp
        LowerMovList.h
        Fight.cpp
        Fight.h
        EnemyFactory.h
        Simulation.cpp
        Simulation.h
        loadPlayer.h
        CombatStrategy.h
        PlayerCombat.h
        EnemyCombat.h
        CombatManager.h
        Save.h
        Serialize.h
)
