import streamlit as st
import pandas as pd
import plotly.express as px

# Set page width
st.set_page_config(layout="wide")

# Load data
url = 'https://github.com/alanjones2/CO2/raw/master/data/countries_df.csv'
df = pd.read_csv(url, usecols=['Entity', 'Year', 'Code', 'Annual CO₂ emissions'])

# Set app title
st.title("CO₂ Emissions by Country")

# Sidebar year selection
st.sidebar.header("Select Year")
year_range = st.sidebar.slider("Select year", min_value=int(df['Year'].min()), max_value=int(df['Year'].max()), value=int(df['Year'].max()))

# Filter data by year
filtered_df = df[df['Year'] == year_range]

# Selectbox for countries
st.sidebar.header("Select Countries")
default_countries = ['India', 'China', 'United States', 'United Kingdom', 'France', 'Germany']
countries = st.sidebar.multiselect("Select countries", filtered_df['Entity'].unique(), default=default_countries)

# Filter data by selected countries
filtered_df = filtered_df[filtered_df['Entity'].isin(countries)]

# Choropleth map of CO2 emissions by country
fig_choropleth = px.choropleth(filtered_df, locations="Code",
                               color="Annual CO₂ emissions",
                               hover_name="Entity",
                               animation_frame="Year",
                               title=f'Annual CO₂ emissions by country from {int(df["Year"].min())} to {int(df["Year"].max())}',
                               height=500,
                               scope='world')

# Bar chart of CO2 emissions by country
if not filtered_df.empty:
    fig_bar = px.bar(filtered_df, x='Entity', y='Annual CO₂ emissions', title=f'Annual CO₂ emissions by country in {year_range}')

    # Set chart headers
    st.header(f"Choropleth Map of CO₂ Emissions by Country in {year_range}")
    st.plotly_chart(fig_choropleth, use_container_width=True)

    st.header(f"Bar Chart of CO₂ Emissions by Country in {year_range}")
    st.plotly_chart(fig_bar, use_container_width=True)

else:
    st.warning("No data available for the selected year and countries.")
