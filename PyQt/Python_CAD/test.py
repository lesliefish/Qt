# -*- coding: UTF-8 -*-
from pyautocad import Autocad, APoint

acad = Autocad(create_if_not_exists = True)
p = APoint(500, 500)

def recur(p, step, layer):
    if layer == 10:
        return
    p2 = next_p(p, layer, step)
    acad.model.AddLine(p, p2)
    layer += 1
    step += 5
    print(step)
    recur(p2, step, layer)

def next_p(p, i, step):
    x = p.x
    y = p.y
    if i % 4 == 0:
        x += step
    elif i % 4 == 1:
        y += step
    elif i % 4 == 2:
        x -= step
    elif i % 4 == 3:
        y -= step
    return APoint(x, y)

def print_obj_name():
    for obj in acad.iter_objects():
        print (obj.ObjectName)
        
if __name__ == '__main__':
    recur(p, 0, 0)
    print_obj_name()
    