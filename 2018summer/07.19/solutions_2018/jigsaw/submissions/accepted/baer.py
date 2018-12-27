#!/bin/python2

import sys
import cProfile

n = int(raw_input())

ps = [list(map(int, raw_input().split())) for _ in range(n)]
pcs = [[] for _ in range(n*2+5)]

largest = 0
for pi in range(n):
	for si in range(4):
		pcs[ps[pi][si]] += [(pi, si)]
		largest = max(largest, ps[pi][si])


cx = [0, -1, 0, 1]
cy = [-1, 0, 1, 0]

def fail():
	print("impossible")
	sys.exit(0)

def gett(num, butnot):
	assert(len(pcs[num]) == 2)
	if pcs[num][0][0] != butnot:
		return pcs[num][0]
	elif pcs[num][1][0] != butnot:
		return pcs[num][1]
	else:
		fail()

grid = None

mix = miy = 0
mx = my = 0

def dfs(p, x, y):
	qu = [None] * n
	placedAt = [None] * n
	
	qu[0] = (p, x, y)
	nw = 1
	nr = 0
	placedAt[p] = (x, y)

	while nr != nw:
		p, x, y = qu[nr]
		nr += 1
		if y < 0 or y >= len(grid) or x < 0 or x >= len(grid[0]):
			fail()
		grid[y][x] = p+1

		for i in range(4):
			if ps[p][i] != 0:
				part = gett(ps[p][i], p)
				otherI = (i+2)%4
				if placedAt[part[0]] != None:
					# check orientation
					if ps[part[0]][otherI] != ps[p][i]:
						fail()
					# check positioning
					if (x + cx[i], y + cy[i]) != placedAt[part[0]]:
						fail()
				else:
					# rotate
					ro = 0
					while ps[part[0]][otherI] != ps[p][i]:
						ro += 1
						ps[part[0]] = ps[part[0]][1:] + [ps[part[0]][0]]
					qu[nw] = (part[0], x + cx[i], y + cy[i])
					placedAt[part[0]] = (x + cx[i], y + cy[i])
					nw += 1

def main():
	global grid, mix, miy, mx, my

	# get dimensions
	ccs = 1
	cur = 0
	curi = 1
	xx = 0
	yy = 0
	while ps[cur][curi] != 0:
		cur, curi = gett(ps[cur][curi], cur)
		curi = (curi + 2) % 4
		ccs += 1
		xx += 1
		if cur == 0:
			fail()
	cur = 0
	curi = 3
	while ps[cur][curi] != 0:
		cur, curi = gett(ps[cur][curi], cur)
		curi = (curi + 2) % 4
		ccs += 1
		if cur == 0:
			fail()

	rrs = 1
	cur = 0
	curi = 0
	while ps[cur][curi] != 0:
		cur, curi = gett(ps[cur][curi], cur)
		curi = (curi + 2) % 4
		rrs += 1
		yy += 1
		if cur == 0:
			fail()
	cur = 0
	curi = 2
	while ps[cur][curi] != 0:
		cur, curi = gett(ps[cur][curi], cur)
		curi = (curi + 2) % 4
		rrs += 1
		if cur == 0:
			fail()

	rs = rrs
	cs = ccs
	if rs * cs != n:
		fail()
	if rs * (cs - 1) + cs * (rs - 1) != largest:
		fail()

	grid = [None] * rs
	for i in range(rs):
		grid[i] = [-1] * cs
	dfs(0, xx, yy)
	for r in range(rs):
		if -1 in grid[r]:
			fail()

	print rs, cs
	#print grid
	print "\n".join([" ".join([str(x) for x in grid[i]]) for i in range(rs)])

if __name__ == "__main__":
	#cProfile.run("main()")
	main()