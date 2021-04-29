x = ddd;
for j = 1:5
figure(j)
[f,xval]=ksdensity(x(:,j));

plot(xval,f)
end