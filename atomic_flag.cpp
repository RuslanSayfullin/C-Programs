#include <iostream>
#include <atomic>
#include <thread>

std::atomic_flag flag = ATOMIC_FLAG_INIT;

void worker(int id)
{
	while (flag.test_and_set(std::memory_order_acquire))
	{
		std::cout << "Worker " << id << ": Waiting..." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	std::cout << "Worker " << id << ": Flag acquired!" << std::endl;

	// Делаем некоторую работу....
	
	flag.clear(std::memory_order_release);
	std::cout << "Worker " << id << ": Flag released!" << std::endl;
}
int main()
{
	std::thread workerThread1(worker, 1);
	std::thread workerThread2(worker, 2);

	// Устанавливаем флаг в "истину"
	flag.test_and_set(std::memory_order_acquire);

	// Подождем некоторое время...
	std::this_thread::sleep_for(std::chrono::seconds(5));

	// Сбрасываем флаг в "ложь"
	flag.clear(std::memory_order_release);

	workerThread1.join();
	workerThread2.join();

	return 0;
}
