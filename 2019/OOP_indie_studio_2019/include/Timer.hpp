/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Timer
*/

#ifndef TIMER_HPP_
#define TIMER_HPP_

#include <iostream>
#include <chrono>
#include <ctime>

class Timer {
    private:
        std::chrono::time_point <std::chrono::system_clock> m_start;
        double m_addedValue = 0;
    public:
        Timer(bool startTimer = false) { if (startTimer) m_start = std::chrono::system_clock::now(); };
        ~Timer() {}
        void start() { m_start = std::chrono::system_clock::now(); };
        void restart() { start(); };
        void setAddedValue(double addedValue) { m_addedValue = addedValue; }
        double getElapsedSeconds() {
            double addedValue = m_addedValue;
            m_addedValue = 0;
            double casted = (std::chrono::duration_cast <std::chrono::milliseconds> (std::chrono::system_clock::now() - m_start).count());
            return (casted / 1000) + addedValue;
        };
};

#endif /* !TIMER_HPP_ */
