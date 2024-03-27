/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_method.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:21:15 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/27 11:35:12 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* function check_cap(ray, t)
x ← ray.origin.x + t * ray.direction.x
z ← ray.origin.z + t * ray.direction.z
return (x² + z²) <= 1
end
function intersect_caps(cyl, ray, xs)
# caps only matter if the cylinder is closed, and might possibly be
# intersected by the ray.
if cyl is not closed or ray.direction.y is close to zero
return
end if
# check for an intersection with the lower end cap by intersecting
# the ray with the plane at y = cyl.minimum
t ← (cyl.minimum - ray.origin.y) / ray.direction.y
if check_cap(ray, t)
add intersection(t, cyl) to xs
end if
# check for an intersection with the upper end cap by intersecting
# the ray with the plane at y=cyl.maximum
t ← (cyl.maximum - ray.origin.y) / ray.direction.y
if check_cap(ray, t)
add intersection(t, cyl) to xs
end if
end function
 */
