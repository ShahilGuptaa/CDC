def my_max(*args):
    return max(args)

def my_sum(*args):
    return sum(args)

def my_min(*args):
    return min(args)

def log_decorator(func):
    def wrapper(*args):
        result = func(*args)
        print(f"LOG: {func.__name__}({', '.join(map(str, args))})")
        return result
    return wrapper

@log_decorator
def my_max(*args):
    return max(args)

@log_decorator
def my_sum(*args):
    return sum(args)

@log_decorator
def my_min(*args):
    return min(args)

if __name__ == "__main__":
    num_queries = int(input())

    for _ in range(num_queries):
        query = input().split()
        dec = input()
        operation = query[0]

        if operation == "my_max":
            arguments = list(map(int,query[1:]))
            print(my_max(*arguments))

        elif operation == "my_sum":
            arguments = list(map(int,query[1:]))
            print(my_sum(*arguments))

        elif operation == "my_min":
            arguments = list(map(int,query[1:]))
            print(my_min(*arguments))

        else:
            print("Invalid query.")
