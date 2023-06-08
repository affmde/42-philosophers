<div align="center">

# 42 - Philosophers

<img alt="mac" src="https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=apple&logoColor=white"/>
<img alt="Linux" src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black"/>
<img alt="Ubuntu" src="https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white"/>
<br>
<img alt="c" src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white"/>
<br>
<img alt="size" src="https://img.shields.io/github/languages/code-size/affmde/42-philosophers"/>
<img alt="total files" src="https://img.shields.io/github/directory-file-count/affmde/42-philosophers"/>
<img alt="repo size" src="https://img.shields.io/github/repo-size/affmde/42-philosophers"/>
<img alt="commits per month" src="https://img.shields.io/github/commit-activity/m/affmde/42-philosophers"/>
</div>

---

## ![description icon](https://cdn-icons-png.flaticon.com/32/2644/2644332.png)  Description
In this project, you will learn the basics of threading a process.
You will see how to create threads and you will discover mutexes
## ![rules icon](https://cdn-icons-png.flaticon.com/32/3251/3251383.png) Rules
You have to write a program for the mandatory part and another one for the bonus part
(if you decide to do the bonus part). They both have to comply with the following rules:
* Global variables are forbidden!
* Your(s) program(s) should take the following arguments:

    - **number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

**number_of_philosophers**: The number of philosophers and also the number of forks.

**time_to_die (in milliseconds)**: If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.

**time_to_eat (in milliseconds)**: The time it takes for a philosopher to eat. During that time, they will need to hold two forks.

**time_to_sleep (in milliseconds)**: The time a philosopher will spend sleeping.

**number_of_times_each_philosopher_must_eat (optional argument)**: If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.

* Each philosopher has a number ranging from 1 to number_of_philosophers.
* Philosopher number 1 sits next to philosopher number number_of_philosophers. Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.
## Output

 * Any state change of a philosopher must be formatted as follows:

        timestamp_in_ms X has taken a fork
        timestamp_in_ms X is eating
        timestamp_in_ms X is sleeping
        timestamp_in_ms X is thinking
        timestamp_in_ms X died
  ***Replace timestamp_in_ms with the current timestamp in milliseconds
and X with the philosopher number.***


* A displayed state message should not be mixed up with another message.
* A message announcing a philosopher died should be displayed no more than 10 ms after the actual death of the philosopher.
* Again, philosophers should avoid dying!


## ![install icon](https://cdn-icons-png.flaticon.com/32/427/427132.png) Install and run

```bash
  $git clone https://github.com/affmde/42-philosophers.git
  $cd 42-philosophers/philo
  $make
  $./philo (number of philos, time to die, time to eat, time to sleep)
```
  Just repplace the values according what you wish to test

## ![relate icon](https://cdn-icons-png.flaticon.com/32/2875/2875800.png) Related projects

 - [42-Minishell](https://github.com/nascimento-jgb/Minishell)
 - [42-Net practice](https://github.com/affmde/42-net_practice)

