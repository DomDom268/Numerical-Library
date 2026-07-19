from invoke import task

@task
def run(c):
    c.run("python vector_cross_validation.py")

