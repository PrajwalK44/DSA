import random

POP_SIZE = 10
CHROMOSOME_LENGTH = 8
MAX_GENERATIONS = 10
MUTATION_RATE = 0.1

def random_chromosome():
    return format(random.randint(0, 255), '08b')

def fitness(chromosome):
    return int(chromosome, 2) ** 2

def select(population):
    return max(random.sample(population, 2), key=fitness)

def crossover(parent1, parent2):
    point = random.randint(1, CHROMOSOME_LENGTH - 1)
    return parent1[:point] + parent2[point:]

def mutate(chromosome):
    index = random.randint(0, CHROMOSOME_LENGTH - 1)
    flipped = '1' if chromosome[index] == '0' else '0'
    return chromosome[:index] + flipped + chromosome[index + 1:]


population = [random_chromosome() for _ in range(POP_SIZE)]
print("Initial Population:", population)

for generation in range(1, MAX_GENERATIONS + 1):
    new_population = []
    for _ in range(POP_SIZE):
        p1, p2 = select(population), select(population)
        child = mutate(crossover(p1, p2))
        new_population.append(child)
    population = sorted(new_population, key=fitness, reverse=True)
    print(f"Generation {generation} Best: {population[0]} x={int(population[0],2)} fitness={fitness(population[0])}")

best = population[0]
print("\nBest Solution:", best, "x =", int(best, 2), "fitness =", fitness(best))

    