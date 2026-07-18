from invoke import task

@task
def run(c):
    c.run("python Python/vector_cross_validation.py")

