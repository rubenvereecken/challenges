__author__ = 'ruben'

def kwargish(**kwargs):
    print (kwargs)
    for key, value in kwargs.items():
        print ("{}. {}".format(key, value))

if __name__ == '__main__':
    kwargish(apple='pie')